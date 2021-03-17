function [volumeoriginal,brainmask,brainmaskNaN, icaSigConc, maskIDXs, volVec, volRaw, smoothedvolume] = initializeStorage(X,nica, nICAconc, brainMask_Threshold, NT)

        
        volumeoriginal=X;

        %PROCESSING - GLOBAL SIGNAL REGRESSION, MOTION REGRESSION, CSF AND WHITE MATTER REGRESSION, BANDPASS
        %FILTERING
        
        B=imgaussfilt3(volumeoriginal,1); % find out second argument and what is twice voxel size
        
        brainmask = zeros(size(B));
        brainmaskNaN = nan(size(B));
        brainmask(B>=brainMask_Threshold)=1;
        brainmaskNaN(B>=brainMask_Threshold)=1;
        
        icaSigConc = nan(nica, sum(brainmaskNaN(:), "omitnan"), nICAconc);
        maskIDXs = ~isnan(brainmaskNaN);
        volVec = zeros(sum(brainmaskNaN(:), "omitnan"), NT);
        volRaw = zeros(sum(brainmaskNaN(:), "omitnan"), NT);
        volRaw(:,1) = X(maskIDXs);
        smoothedvolume=zeros(sum(brainmaskNaN(:), "omitnan"), NT);
end

