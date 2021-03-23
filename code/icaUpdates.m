function [icasig0,icaSigConc,ica_ind, ncomp] = icaUpdates(sm_vol, icasig0, ica_ind, icaSigConc, LeftX, RightX, b, nbhd_idxs, nICAconc)
rng default;
proc_vol = sm_vol(:, LeftX: RightX);
[icasig, A, ~] = fastica(proc_vol'/std(proc_vol(:)), 'lastEig', 15, 'numOfIC', 30, 'verbose', 'off');
ncomp = size(icasig,1);

if isnan(icasig0)
    ica_scores = mean(icasig(:, nbhd_idxs),2, "omitnan");
    signs_ica = sign(ica_scores);
    
    [~, ica_score_order] = sort(abs(ica_scores), 'descend');
    icasig0 = diag(signs_ica) * icasig;
    icasig0 = icasig0(ica_score_order,:);
    icaSigConc(1:ncomp,:,ica_ind) = icasig0;
    ica_ind = ica_ind + 1;
else
    icasig0_mean = mean(icaSigConc, 3, "omitnan");
    [~, ~, icasig_new] = ICA_reorder1(icasig0_mean, icasig, nbhd_idxs, A, b);
    icasig0 = icasig_new;
    
    if ica_ind <= nICAconc
        icaSigConc(1:ncomp,:,ica_ind) = icasig0;
    else
        icaSigConc(:,:,1:(nICAconc-1)) =  icaSigConc(:,:,2:nICAconc);
        icaSigConc(1:ncomp,:,nICAconc) = icasig0;
    end
    ica_ind = ica_ind+1;
end

end

