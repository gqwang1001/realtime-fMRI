function [orders, signall, icasig_new] = ICA_reorder1(icasig0, icasig, nbhd_idxs, A, actVoxel)

n0 = size(icasig0,1);
n1 = size(icasig,1);
orders = zeros(n1, 1);
signs = ones(n1, 1);
signs1 = ones(n1, 1);

icasig_new = icasig;
icasig_flipsigns = icasig;

for i = 1:n1
    r = corrcoef(A(:,i), actVoxel);
    signs(i) = sign(r(1,2));
    icasig_flipsigns(i,:) = signs(i) * icasig(i,:);
end

corr_ica = corr(icasig0(:, nbhd_idxs)', icasig_flipsigns(:, nbhd_idxs)');

for i = 1:n0

    [~, Ind] = max(abs(corr_ica(:)));
    [Indrow, Indcol] = ind2sub(size(corr_ica), Ind);
    orders(Indrow) = Indcol;
    signs1(Indrow) = sign(corr_ica(Ind));

    corr_ica(Indrow,:) = 0;
    corr_ica(:,Indcol) = 0;
    
%     icasig_new(Indrow,:) = signs(Indrow) * icasig(Indcol, :);
    icasig_new(Indrow,:) = signs1(Indrow) * icasig_flipsigns(Indcol, :);
     
end

if n0<n1 
   orders((n0+1):n1) = setdiff(1:n1, orders(1:n0));
end
signall = signs .* signs1;

end

