function [registered, nuisanceX, reg_tform] = rt_preprocess(volumenew, volumeoriginal, brainmask, csf_mask, wm_mask, iTR, tol, tform_old)
        %PROCESSING - GLOBAL SIGNAL REGRESSION, MOTION REGRESSION, CSF AND WHITE MATTER REGRESSION, BANDPASS
        %FILTERING
        % Motion Regression
        
        [optimizer, metric] = imregconfig('monomodal');
        optimizer.GradientMagnitudeTolerance = tol;
%         registered = imregister(volumenew, volumeoriginal, 'rigid', optimizer, metric);
        reg_tform  = imregtform(volumenew, volumeoriginal, 'rigid', optimizer, metric, 'InitialTransformation', tform_old);
        registered = imwarp(volumenew, reg_tform, 'OutputView',imref3d(size(volumeoriginal)));
        motion_Pars = motionPar(reg_tform);
        
        %GSR with brain mask
        maskedbrain = registered.*brainmask;
        GSbrain = mean(maskedbrain(:));
        
        % CSF and White Matter Regression
        csfSignal = registered .* csf_mask;
        csfMean = mean(csfSignal(:));
        wmSignal = registered .* wm_mask;
        wmMean = mean(wmSignal(:));
        
        % Bandpass filtering 0.01-0.1Hz
        
%         bp_basis = rt_dctmtx(.1, .01, iTR);
        
        nuisanceX = [motion_Pars,motion_Pars.^2, csfMean, wmMean];
%         nuisanceX = [motion_Pars, GSbrain,, bp_basis];

end

