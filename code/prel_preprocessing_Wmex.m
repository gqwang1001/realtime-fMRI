function [nuisX_comb,tform_old, volVec, volRaw] = prel_preprocessing_Wmex(i, X, maskIDXs, volRaw, slice_times, slice_indices, tr, brainmask, tform_old, volVec, nuisX_comb, volumeoriginal, wm_csf_mask, motion_tol)
        volRaw(:,i) = X(maskIDXs);
        volVec_slc = rt_slice_time_correction_mex(volRaw(:, 1:i), slice_times, slice_indices, tr, 0);
        
        %PROCESSING - GLOBAL SIGNAL REGRESSION, MOTION REGRESSION, CSF AND WHITE MATTER REGRESSION, BANDPASS
        %FILTERING
        
        volNew_slc = brainmask; volNew_slc(maskIDXs) = volVec_slc(:, i);
        [registered, nuisX, tform_old] = rt_preprocess(volNew_slc, volumeoriginal, brainmask, wm_csf_mask.csf_mask, wm_csf_mask.wm_mask, i*tr, motion_tol, tform_old);
        volVec(:,i-1) = registered(maskIDXs);
        
        if i == 2
            nuisX_comb(i-1,:) = [zeros(1, 12) nuisX];
%             ncol_nx = size(nuisX_comb, 2);
        else
            nuisX_comb(i-1,:) = [nuisX(1:6) - nuisX_comb(i-2, 13:18), ...
                (nuisX(1:6) - nuisX_comb(i-2, 13:18)).^2, ...
                nuisX];
        end
end