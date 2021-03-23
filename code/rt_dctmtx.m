function basis = rt_dctmtx(freq_l, freq_h, N)

% Calculate the DCT basis for frequency less than freq_l and higher than
% freq_h
% OUTPUT
% Basis evaluated at t.
% Created by Guoqing Wang, 08/04/2020.
if ceil(freq_h * N + .5) < N
    Ks = [1:floor(freq_l * N + .5)  ceil(freq_h * N + .5) : N];
else
    Ks = 1:floor(freq_l * N + .5);
end

basis_all = dctmtx(N);
basis = basis_all(:, Ks);
   
end

