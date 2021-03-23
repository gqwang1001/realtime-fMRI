function [VOL_proc,volRaw, tform_old, volVec, smoothedvolume, nuisX_comb, ATinv] =...
    preprocessing(i, I_pre, nuisX_comb, volVec, brainmask, smooth_sig, maskIDXs, smoothedvolume,X, volRaw, ...
    slice_times,  slice_indices, tr,volumeoriginal, wm_csf_mask, motion_tol, tform_old, bp_filt, ATinv)

        if i == I_pre+1
            ATinv = pinv(nuisX_comb(1:(i-1), :)' * nuisX_comb(1:(i-1), :));
            
            vol_processed = volVec(:, 1:(i-2))*(eye(i-2) - nuisX_comb(1:(i-2), :) * ATinv * nuisX_comb(1:(i-2), :)')' ;
            %             Gaussian filtering
            for j = 2: I_pre
                volProc3d = brainmask;   
                volProc3d(maskIDXs) = vol_processed(:,j-1);
                sm_vol = imgaussfilt3(volProc3d, smooth_sig); % find out second argument and what is twice voxel size
                smoothedvolume(:, j-1) = sm_vol(maskIDXs);
            end
        end
        
        % SLICE TIME CORRECTION
        volRaw(:, i) = X(maskIDXs);
        volVec_slc = rt_slice_time_correction(volRaw(:,1:i), slice_times, slice_indices, tr, 1);
        % NUISANCE REGRESSION (Motion (24 parameters), CSF and WM means);
        
        volNew_slc = brainmask; volNew_slc(maskIDXs) = volVec_slc;
        [registered, nuisX, tform_old] = rt_preprocess(volNew_slc, volumeoriginal, brainmask, wm_csf_mask.csf_mask, wm_csf_mask.wm_mask, i*tr, motion_tol, tform_old);
        nrow = i-1;
        nuisX1 = [nuisX(1:6) - nuisX_comb(i-2, 13:18), ...
            (nuisX(1:6) - nuisX_comb(i-2, 13:18)).^2, ...
            nuisX];
        volVec(:,i-1) = registered(maskIDXs);
        [vol_processed, ATinv] = fastfMRI(nuisX_comb(1:(i-2), :), volVec(:,1:(i-2)), ATinv, nuisX1', volVec(:,i-1));
        nuisX_comb(i-1, :) = nuisX1;
        
        % Spatial Smoothing
        volProc3d = brainmask; 
        volProc3d(maskIDXs) = vol_processed(:,i-1);
        B = imgaussfilt3(volProc3d, smooth_sig); % find out second argument and what is twice voxel size
        smoothedvolume(:,(i-1)) =  B(maskIDXs);
        
        % Bandpass filtering
        bp_basis = rt_dctmtx(bp_filt(1), bp_filt(2), nrow);
        VOL_proc =  smoothedvolume(:, 1:(i-1)) * (eye(nrow) - (bp_basis * bp_basis'));
end

