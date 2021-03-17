function [sm_vol, Mval,norMval, norMvaldetrend] = MValupdates(VOL_proc, nbhd1_ind, nbhd2_ind)
%     if i > I_pre
sm_vol = VOL_proc(:, 2:end);

ROIval1= sm_vol(nbhd1_ind, :);
ROIval2= sm_vol(nbhd2_ind, :);
Mval(:,1)= mean(ROIval1, 1);
Mval(:,2)= mean(ROIval2, 1);

norMval(:,1)=zscore(Mval(:,1));
norMval(:,2)=zscore(Mval(:,2));

norMvaldetrend(:,1)=detrend(norMval(:,1));
norMvaldetrend(:,2)=detrend(norMval(:,2));
end

