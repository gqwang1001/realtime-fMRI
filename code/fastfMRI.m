function [eVec, AT1Inv] = fastfMRI(XT,YT, ATInv, xT1, yT1)
% This function implements the fastFMRI algorithm
% INPUT
%   XT (T-by-p) : the collection of nuisance variable. xT' = [x1 x2 ... xT];
%   YT (n-by-T) : a voxel at tr 1:T;
%   ATinv (p-by-p) : ATinv = inv(XT' * XT)
%   xT1 (p-by-1) : a collection of nuisance vairable at tr (T+1)
%   yT1 (n-by-1) : a voxel at tr (T+1)
% OUTPUT
%   eVec ((T+1)-by-1) : eVec = (I - XT1*inv(XT1' * XT1)* XT1')* YT1
%   the residueal for the next TR after having regressed out nuisances
%   AT1Inv (p-by-p) : AT1Inv = inv(XT1' * XT1)

bT1 = xT1' * ATInv * xT1;
% betaT = ATInv * XT' * YT; 
betaT = YT * XT * ATInv'; % n by p
AT1Inv = ATInv - ATInv * (xT1 * xT1') * ATInv / (1 + bT1);

% eT = YT - XT * betaT;
% eT1 = yT1 - xT1' * betaT;
eT = YT - betaT * XT'; % n by T
eT1 = yT1 - betaT * xT1; % n by 1

% eVec = [eT - XT * ATInv * xT1 * eT1 / (1+bT1) ; eT1 / (1+bT1)];
eVec = [eT - eT1 * xT1' * ATInv' * XT' / (1+bT1)  eT1 / (1+bT1)];
end
