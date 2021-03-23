function cor= corr_pairwise(A,B)

A_centered = A - mean(A, 1, 'omitnan');
B_centered = B - mean(B, 1, 'omitnan');

n = size(A,1);

A_std = std(A);
B_std = std(B);

cov_AB = A_centered' * B_centered ./ (n-1);
std_prod = A_std' * B_std;

cor = cov_AB ./ std_prod;

end

