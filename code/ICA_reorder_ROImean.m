function [orders, signall, icasig_new] = ICA_reorder_ROImean(icasig0, icasig, nbhd_idxs, A, actVoxel)

n0 = size(icasig0,1);
n1 = size(icasig,1);
% orders = zeros(n1, 1);
signs = ones(n1, 1);
% signs1 = ones(n1, 1);

% icasig_new = icasig;
icasig_flipsigns = icasig;

for i = 1:n1
    r = corrcoef(A(:,i), actVoxel);
    signs(i) = sign(r(1,2));
    icasig_flipsigns(i,:) = signs(i) * icasig(i,:);
end

ica_nbhd = icasig_flipsigns(:, nbhd_idxs);
ica_nbhd(ica_nbhd<0) = nan;

sigMeans = mean(ica_nbhd,2,'omitnan');

[~, orders] = sort(sigMeans,  'descend');

icasig_new = icasig_flipsigns(orders,:);

signall = signs;

end

