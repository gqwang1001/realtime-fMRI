function [orders, signs, icasig_new] = ICA_reorder(icasig0, icasig, nbhd_idxs, A, actVoxel)

corr_ica = corr(icasig0(:, nbhd_idxs)', icasig(:, nbhd_idxs)');

[n0, n1] = size(corr_ica);
orders = zeros(n1, 1);
signs = ones(n1, 1);

icasig_new = icasig;

for i = 1:n0

    [~, Ind] = max(abs(corr_ica(:)));
    [Indrow, Indcol] = ind2sub(size(corr_ica), Ind);
    orders(Indrow) = Indcol;
    signs(Indrow) = sign(corr_ica(Ind));

    corr_ica(Indrow,:) = 0;
    corr_ica(:,Indcol) = 0;
    
    icasig_new(Indrow,:) = signs(Indrow) * icasig(Indcol, :);
end

if n0<n1 
   orders((n0+1):n1) = setdiff(1:n1, orders(1:n0));
end

end

