function [nbhd_idxs,nbhd1_ind, nbhd2_ind] = find_nbhd_inds(answer,brainmaskNaN, maskIDXs, ROI_size)


nbhd_roi1 = [str2num(answer{1,1}) + (-ROI_size:ROI_size);...
    str2num(answer{2,1})+ (-ROI_size:ROI_size);...
    str2num(answer{3,1})+ (-ROI_size:ROI_size)];
nbhd_roi2 = [str2num(answer{4,1})+ (-ROI_size:ROI_size);...
    str2num(answer{5,1})+ (-ROI_size:ROI_size);...
    str2num(answer{6,1})+ (-ROI_size:ROI_size)];

nbhd_ind = brainmaskNaN;
nbhd_ind(nbhd_roi1(1,:),nbhd_roi1(2,:),nbhd_roi1(3,:)) = 2;
nbhd_ind(nbhd_roi2(1,:),nbhd_roi2(2,:),nbhd_roi2(3,:)) = 3;

nbhd_ind = nbhd_ind(maskIDXs);
nbhd1_ind = find(nbhd_ind==2);
nbhd2_ind = find(nbhd_ind==3);

nbhd_idxs =	[nbhd1_ind; nbhd2_ind];

end

