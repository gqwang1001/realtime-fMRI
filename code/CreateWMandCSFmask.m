function wm_csf_mask = CreateWMandCSFmask(TissueApriori,brainmask)

[optimizer, metric] = imregconfig('monomodal');

tform_apriori = imregtform(imrotate3(TissueApriori.brainMask, 90, [0 0 1]), brainmask, 'affine',optimizer,metric);
tform_apriori_out = affineOutputView(size(brainmask), tform_apriori,'BoundsStyle','SameAsInput');
wm_apriori = imwarp(imrotate3(TissueApriori.WM, 90, [0 0 1]), tform_apriori, 'OutputView', tform_apriori_out);
csf_apriori = imwarp(imrotate3(TissueApriori.CSF, 90, [0 0 1]), tform_apriori, 'OutputView', tform_apriori_out);

wm_mask = zeros(size(wm_apriori));
wm_mask(wm_apriori>.95) = 1;
csf_mask = zeros(size(csf_apriori));
csf_mask(csf_apriori>.9) = 1;

wm_csf_mask = [];
wm_csf_mask.wm_mask = wm_mask;
wm_csf_mask.csf_mask = csf_mask;

end

