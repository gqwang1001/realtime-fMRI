

clearvars; close all;

pause('on');
% workingdir='/Users/harissair/Desktop/realtime_test_data/real_time';
% addpath('/Users/harissair/Desktop/realtime_test_data/scripts');

workingdir = ".";
addpath ../code;
motion_tol = 1e-7;

I_pre = 30; % Time Needed for preprocessing
window_width = 50;
tr=2; 
cd(workingdir);
seedval=[];
ROI_size=3;
brainMask_Threshold = 0.005;
bp_filt = [.01, 10];
NmotionPars = 6;
size3d = [64, 64, 36];
tform_old = affine3d(eye(4)); 
imINIT = zeros(64,64,36);
smooth_sig = 3/2.3556;
vol_pre=rand(64,64,36,I_pre-1,'single');  
sm_vol_4d = zeros(64, 64, 36, I_pre-1);
nica = 15;
ica_ind = 1;
nICAconc = 20;

icasig0 = nan;

% load the white matter and CSF mask
TissueApriori = [];
TissueApriori.CSF = im2double(niftiread("../SPM8_apriori/csf.nii"));
TissueApriori.WM = im2double(niftiread("../SPM8_apriori/white.nii"));
TissueApriori.brainMask = im2double(niftiread("../SPM8_apriori/brainmask.nii"));
TissueApriori.grey = im2double(niftiread("../SPM8_apriori/grey.nii"));

[optimizer, metric] = imregconfig('monomodal');

NT = 1e3;
ATinv = [];
volVec = zeros(NT, 64*64*36);
smoothedvolume=zeros(NT, 64*64*36);
nuisX_comb = zeros(NT, 26);
ROIval1 = [];
volRaw =zeros(NT, 64*64*36);

answer = {'48','26','25','48','43','25'}';

f1 = figure(1);
f1.Position =  [200, 500, 500, 500];
f1.Name = 'Time Series';
set(gca, 'xlimmode','manual','ylimmode','manual','zlimmode','manual',...
         'climmode','manual','alimmode','manual');
set(f1,'doublebuffer','off');
% s3 = subplot(3,1,3); im3 = imagesc(0); colorbar; axis off;
% set(s3, 'CLim', [-1, 1]);
% s3.Colormap = colormap(jet);
% s3.Title.String = 'corr';
s1 = subplot(3,1,1); fill_s1 = fill(s1, [1,1,2,2], [0,1e-6, 1e-6, 0], 'y', "FaceAlpha", .1); hold on; line_s1 = plot(s1, zeros(3,2)); hold off;
s2 = subplot(3,1,2); fill_s2 = fill(s2, [1,1,2,2], [0,1e-6, 1e-6, 0], 'y', "FaceAlpha", .1); hold on; line_s2 = plot(s2, zeros(3,2)); hold off;
s3 = subplot(3,1,3); fill_s3 = fill(s3, [1,1,2,2], [0,1e-6, 1e-6, 0], 'y', "FaceAlpha", .1); hold on; line_s3 = plot(s3, zeros(3,2)); hold off;
% legend(s3, 'right', 'left', 'Location','SouthOutside', 'Orientation', 'horizontal');
set(f1,'visible','off');

f2 = figure(2);
f2.Position =  [1000, 500, 1200, 800];
f2.Name = 'Correlation Map'; 
f2subplots = {};
f2axs = {};
set(f2,'visible','off');

for fig = 1:12
    f2axs{fig,1} = subplot(3,4, fig);
    f2subplots{fig, 1} = imagesc(f2axs{fig,1}, imINIT(:,:,2*fig+7));
    title(f2axs{fig,1}, ['Slice ', num2str(2*fig+7)]);
    colormap(f2axs{fig,1}, 'jet'); colorbar(f2axs{fig,1}); caxis(f2axs{fig,1},[-1,1]);
end


f3 = figure(3);
f3.Position =  [1000, 500, 1200, 800];
f3.Name = 'IC Map'; 
f3subplots = {};
f3axs = {};
set(f3,'visible','off');

for fig = 1:12
    f3axs{fig,1} = subplot(3,4, fig);
    f3subplots{fig, 1} = imagesc(f3axs{fig,1}, imINIT(:,:,2*fig+7));
    title(f3axs{fig,1}, ['IC ', num2str(fig)]);
    colormap(f3axs{fig,1}, 'jet'); colorbar(f3axs{fig,1}); 
%     caxis(f3axs{fig,1},[2,5]);
end

inds = 4:300;
for i = 1: length(inds)
    tic
    nextfile=['*' sprintf('%03d',inds(i)+1) '.dcm'];
    filename=dir(nextfile);
    
    while isempty(filename)==1
        pause(tr)
        disp(['waiting ', num2str(tr),' seconds for next file']);
        filename=dir(nextfile);
    end
    
    dcmfile=dir(['*' sprintf('%03d',inds(i)) '.dcm']);
    dicomfile=dcmfile.name;

    display(dicomfile)
    
    %siemens demosaic function
    X=siemensdemosaic(dicomfile);

    %create 4D image file

    if i==1
 
        % LOAD THE FIRST IMAGE

        volumeoriginal=X;
%         volRaw = [volRaw; X(:)'];
        volRaw(i, :) = X(:);
        % Create the Slice_Indices for the Slice Time Correction
        dcminfo = dicominfo(dcmfile.name);
        
        if isa(dcminfo.Private_0019_1029, 'uint8')
                slice_times = typecast(uint8(dcminfo.Private_0019_1029), 'double')/1e3;
        else
            slice_times = dcminfo.Private_0019_1029/1e3;
        end
            
        testM = X;
        for j = 1:length(slice_times)   
            testM(:,:,j) = j;
        end


        %PROCESSING - GLOBAL SIGNAL REGRESSION, MOTION REGRESSION, CSF AND WHITE MATTER REGRESSION, BANDPASS
        %FILTERING

        B=imgaussfilt3(volumeoriginal,1); % find out second argument and what is twice voxel size
%         smoothedvolume(:,:,:,1)=B;
        
        brainmask = zeros(size(B));
        brainmaskNaN = nan(size(B));
        brainmask(B>=brainMask_Threshold)=1;
        brainmaskNaN(B>=brainMask_Threshold)=1;
        
        icaSigConc = nan(nica, sum(brainmaskNaN(:), "omitnan"), nICAconc);
        
        testM = testM .* brainmask;
        slice_indices = testM(:);
        %create brain mask from smoothed fmri volume

%       
        if isempty(answer)
            
                %pick motor cortex
                f_slices = figure('Position', [500, 500, 1000, 800]);
                subplot(2,3,1)
                imagesc(X(:,:,24));colormap(gray);
                title(24);

                subplot(2,3,2)
                imagesc(X(:,:,25));colormap(gray);
                title(25);

                subplot(2,3,3)
                imagesc(X(:,:,26));colormap(gray);
                title(26);

                subplot(2,3,4)
                imagesc(X(:,:,27));colormap(gray);
                title(27);

                subplot(2,3,5)
                imagesc(X(:,:,28));colormap(gray);
                title(28); 

                subplot(2,3,6)
                imagesc(X(:,:,29));colormap(gray);
                title(29);          

                pause;

                prompt = {'Choose the slice'};
                dlgtitle='Input';
                ans_slice = inputdlg({'Right Motor Cortex', 'Left Motor Cortex'},...
                                       'Choice of Slice',...
                                       [1 80; 1 80] ); 
                close(f_slices);

                %pick motor cortex hires

                f_slice = figure('Position', [500, 500, 500, 500]); 
                imagesc(X(:,:,str2num(ans_slice{1,1})));
                title(['Slice ', ans_slice{1,1},' (Right Motor Cortex)']);
                colormap(gray);
                u1 = drawcrosshair;
                pause;
                answer = cell(6,1);
                answer{1,1} = num2str(round(u1.Position(2)));
                answer{2,1} = num2str(round(u1.Position(1)));
                answer{3,1} = ans_slice{1,1};
                close(f_slice);

                f_slice1 = figure('Position', [500, 500, 500, 500]);
                imagesc(X(:,:,str2num(ans_slice{2,1})));
                title(['Slice ', ans_slice{2,1},' (Left Motor Cortex)']);
                colormap(gray);
                u2 = drawcrosshair;
                pause;
                answer{4,1} = num2str(round(u2.Position(2)));
                answer{5,1} = num2str(round(u2.Position(1)));
                answer{6,1} = ans_slice{2,1};
                close (f_slice1);
        
        end
        
        uif = uifigure;
        d = uiprogressdlg(uif,'Title','Processing Preliminary Scans',...
        'Indeterminate','on');
%     pause; 
% 
%         prompt = {'enter right motor seed voxel x coordinate', ...
%                 'enter right motor seed voxel y coordinate', ...
%                 'enter right motor seed voxel z coordinate (image title)', ...
%                 'enter left motor seed voxel x coordinate', ...
%                 'enter left motor seed voxel y coordinate', ...
%                 'enter left motor seed voxel z coordinate (image title)'};
% 
% 
%         dlgtitle='Input';
%         answer = inputdlg(prompt,dlgtitle); 
% 
%         close(figure(1));

        nbhd_roi1 = [str2num(answer{1,1}) + [-ROI_size:ROI_size];...
                     str2num(answer{2,1})+ [-ROI_size:ROI_size];...
                     str2num(answer{3,1})+ [-ROI_size:ROI_size]];
        nbhd_roi2 = [str2num(answer{4,1})+ [-ROI_size:ROI_size];...
                     str2num(answer{5,1})+ [-ROI_size:ROI_size];...
                     str2num(answer{6,1})+ [-ROI_size:ROI_size]];
        nbhd_ind = brainmaskNaN;
        nbhd_ind(nbhd_roi1(1,:),nbhd_roi1(2,:),nbhd_roi1(3,:)) = 2;
        nbhd_ind(nbhd_roi2(1,:),nbhd_roi2(2,:),nbhd_roi2(3,:)) = 3;
        nbhd1_ind = find(nbhd_ind==2);
        nbhd2_ind = find(nbhd_ind==3);
        
        brainMaskvec = nbhd_ind(:);
        brainMaskvec1 = nbhd_ind(~isnan(brainMaskvec));
        nbhd_idxs =	[find(brainMaskvec1==2); find(brainMaskvec1==3)];
        
        % CREATE THE WM AND CSF MASK
        tform_apriori = imregtform(imrotate3(TissueApriori.brainMask, 90, [0 0 1]), brainmask, 'affine',optimizer,metric);
        tform_apriori_out = affineOutputView(size(brainmask), tform_apriori,'BoundsStyle','SameAsInput');
        wm_apriori = imwarp(imrotate3(TissueApriori.WM, 90, [0 0 1]), tform_apriori, 'OutputView', tform_apriori_out);
        csf_apriori = imwarp(imrotate3(TissueApriori.CSF, 90, [0 0 1]), tform_apriori, 'OutputView', tform_apriori_out);

        wm_mask = zeros(size(wm_apriori));
        wm_mask(wm_apriori>.95) = 1;
        csf_mask = zeros(size(csf_apriori));
        csf_mask(csf_apriori>.9) = 1;
        

    elseif i <= I_pre
        % Prepare images for preprocessing
        volumenew = X;
        volRaw(i, :) = X(:);
        
        volVec_slc = rt_slice_time_correction_mex(volRaw(1:i,:), slice_times, slice_indices, tr, 0);
        
        
        if ~exist('volumeoriginal', 'var')
            volumeoriginal = reshape(volVec_slc(1,:), size3d);
        end
        
        %PROCESSING - GLOBAL SIGNAL REGRESSION, MOTION REGRESSION, CSF AND WHITE MATTER REGRESSION, BANDPASS
        %FILTERING
        volNew_slc = reshape(volVec_slc(i,:), size3d);
        
        [registered, nuisX, tform_old] = rt_preprocess(volNew_slc, volumeoriginal, brainmask, csf_mask, wm_mask, i*tr, motion_tol, tform_old);
        volVec(i-1,:) = registered(:)';
        
        if i == 2
            nuisX_comb(i-1,:) = [zeros(1, 12) nuisX];
            ncol_nx = size(nuisX_comb, 2);
        else
            nuisX_comb(i-1,:) = [nuisX(1:6) - nuisX_comb(i-2, 13:18), ...
                              (nuisX(1:6) - nuisX_comb(i-2, 13:18)).^2, ...
                               nuisX];
        end

    else
        
        close(d);
        set(f3,'visible','on');

        if i == I_pre+1
            
            ATinv = pinv(nuisX_comb(1:(i-1), :)' * nuisX_comb(1:(i-1), :));
            vol_processed = (eye(i-2) - nuisX_comb(1:(i-2), :) * ATinv * nuisX_comb(1:(i-2), :)') * volVec(1:(i-2), :);
            
%             Gaussian filtering
            
            for j = 2: I_pre
                sm_vol_4d(:,:,:,j-1) = imgaussfilt3(reshape(vol_processed(j-1,:), size3d), smooth_sig); % find out second argument and what is twice voxel size
%                 smoothedvolume = [smoothedvolume; B(:)'];
            end
            
           sm_vol_2d = reshape(sm_vol_4d, [], I_pre - 1);
           smoothedvolume(1:(i-2),:) = sm_vol_2d';
           figure(1);
           figure(2);
        end
        
          % SLICE TIME CORRECTION  
          volumenew = X;
          volRaw(i, :) = X(:);
          volVec_slc = rt_slice_time_correction_mex(volRaw(1:i, :), slice_times, slice_indices, tr, 1);
          % NUISANCE REGRESSION (Motion (24 parameters), CSF and WM means);
          %
          volNew_slc = reshape(volVec_slc, size3d);
          [registered, nuisX, tform_old] = rt_preprocess(volNew_slc, volumeoriginal, brainmask, csf_mask, wm_mask, i*tr, motion_tol, tform_old);
          nrow = i-1;

          nuisX1 = [nuisX(1:6) - nuisX_comb(i-2, 13:18), ...
                   (nuisX(1:6) - nuisX_comb(i-2, 13:18)).^2, ...
                    nuisX];
          
          [vol_processed, ATinv] = fastfMRI_mex(nuisX_comb(1:(i-2), :), volVec(1:(i-2), :), ATinv, nuisX1', registered(:)');
          
          nuisX_comb(i-1, :) = nuisX1;
          volVec(i-1, :) = registered(:)';

          % Spatial Smoothing
          
          B=imgaussfilt3(reshape(vol_processed(i-1,:), size3d), smooth_sig); % find out second argument and what is twice voxel size
          
          smoothedvolume((i-1), :) =  B(:)';
          % Bandpass filtering 
          
          bp_basis = rt_dctmtx(bp_filt(1), bp_filt(2), nrow);
          VOL_proc = (eye(nrow) - bp_basis * bp_basis') * smoothedvolume(1:(i-1), :);
          

%     if i > I_pre
        sm_vol = VOL_proc(2:end, :);

        if isempty(ROIval1)
            ROIval1= sm_vol(:, nbhd1_ind);
            ROIval2= sm_vol(:, nbhd2_ind);
            clear Mval;
            Mval(:,1)= mean(ROIval1, 2);
            Mval(:,2)= mean(ROIval2, 2);
        else
            ROIval1= sm_vol(end, nbhd1_ind);
            ROIval2= sm_vol(end, nbhd2_ind);
            Mval = [Mval; [mean(ROIval1(:)), mean(ROIval2(:))]];
        end
            
        clear norMval;
        norMval(:,1)=zscore(Mval(:,1));
        norMval(:,2)=zscore(Mval(:,2));
        
        clear norMvaldetrend;
        norMvaldetrend(:,1)=detrend(norMval(:,1));
        norMvaldetrend(:,2)=detrend(norMval(:,2));

%         time series correlations
        
        if rem(i , 1)==0
            
            
            [Tidx, ~] = size(Mval);
            
            LeftX = max(1, Tidx - window_width);RightX = Tidx;
            set(line_s1, {"YData"}, {Mval(:,1); Mval(:,2)});
            FloorY = min(s1.YLim); CeilY = max(s1.YLim);
            set(fill_s1, "Vertices", [LeftX, LeftX, RightX, RightX; FloorY, CeilY, CeilY, FloorY]');
            s1.Title.String = ['Raw Signal (Correlation = ' num2str(corr(Mval(LeftX: RightX, 1),Mval(LeftX: RightX,2))) ')'];
            drawnow
            
            set(line_s2,{"YData"}, {norMval(:,1); norMval(:,2)});
            FloorY = min(s2.YLim); CeilY = max(s2.YLim);
            set(fill_s2, "Vertices", [LeftX, LeftX, RightX, RightX; FloorY, CeilY, CeilY, FloorY]');
            s2.Title.String = ['Normalized Signal (Correlation = ' num2str(corr(norMval(LeftX: RightX,1),norMval(LeftX: RightX,2))) ')'];
            drawnow

            set(line_s3, {"YData"}, {norMval(:,1); norMval(:,2)});
            FloorY = min(s3.YLim); CeilY = max(s3.YLim);
            set(fill_s3, "Vertices", [LeftX, LeftX, RightX, RightX; FloorY, CeilY, CeilY, FloorY]');
            s3.Title.String = ['Detrended Signal (Correlation = ' num2str(corr(norMvaldetrend(LeftX: RightX,1),norMvaldetrend(LeftX: RightX,2))), ')'];
            drawnow
        
        % add DCC plots and color bar
%         
            b = norMval(LeftX: RightX,1) - mean(norMval(LeftX: RightX,1));
            sd_b = std(norMval(LeftX: RightX, 1));            
            sd_vol_b = std(sm_vol) * sd_b;
            vol_centering = sm_vol(LeftX: RightX, :) - mean(sm_vol);
            cov_volB = b' * vol_centering / (size(b,1)-1);
            corr_vol = cov_volB ./ sd_vol_b;
            
            Corrmap = reshape(corr_vol', size3d) .* brainmaskNaN;
            
        % correlation maps with first seed - c

            for fig = 1:12
                    set(f2subplots{fig, 1}, 'CData', Corrmap(:,:,fig*2+7));
            end
            drawnow
                        
            rng default;
            proc_vol = sm_vol(LeftX: RightX, ~isnan(brainmaskNaN(:)));
            [icasig, A, ~] = fastica(proc_vol/std(proc_vol(:)), 'lastEig', 15, 'numOfIC', 30, 'verbose', 'off');
            
            ncomp = size(icasig,1);
            
            if isnan(icasig0)
%                 icasig0 = icasig;
            
                ica_scores = mean(icasig(:, nbhd_idxs),2, "omitnan");
                signs_ica = sign(ica_scores);
                
                [ica_score_sorted, ica_score_order] = sort(abs(ica_scores), 'descend'); 
%                 ica_score_order_sign = 1+0*ica_score_order;
                
                icasig0 = diag(signs_ica) * icasig;
                icasig0 = icasig0(ica_score_order,:);
                icaSigConc(1:ncomp,:,ica_ind) = icasig0;
                ica_ind = ica_ind + 1;
            else

                    
                icasig0_mean = mean(icaSigConc, 3, "omitnan");
                [ica_score_order, ica_score_order_sign, icasig_new] = ICA_reorder1(icasig0_mean, icasig, nbhd_idxs, A, b);
                icasig0 = icasig_new;
                                
                if ica_ind <= nICAconc
                    icaSigConc(1:ncomp,:,ica_ind) = icasig0;
                else
                    icaSigConc(:,:,1:(nICAconc-1)) =  icaSigConc(:,:,2:nICAconc);
                    icaSigConc(1:ncomp,:,nICAconc) = icasig0;
                end
                ica_ind = ica_ind+1;
            end
            
            icacomp = brainmaskNaN;
            for fig = 1:min(12, ncomp)
                    icacomp(~isnan(icacomp)) = icasig0(fig, :);
                    set(f3subplots{fig, 1}, 'CData', icacomp(:,:,25));
            end
            
            drawnow
        end
    end
% 

toc
end