function [TissueApriori] = loadMask(maskdir)


TissueApriori = [];
TissueApriori.CSF = im2double(niftiread(maskdir+"csf.nii"));
TissueApriori.WM = im2double(niftiread(maskdir+"white.nii"));
TissueApriori.brainMask = im2double(niftiread(maskdir+"brainmask.nii"));
TissueApriori.grey = im2double(niftiread(maskdir+"grey.nii"));


end

