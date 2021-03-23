function [slice_times, slice_indices] = sliceTimeInfo(dcmfile, maskIDXs)
%Acquire the slice time info
dcminfo_spm = spm_dicom_headers(dcmfile.folder+"/"+dcmfile.name);
slice_times_info = dcminfo_spm{1,1}.CSAImageHeaderInfo;
slice_info_idx = cellfun(@(x) isequal(x, 'MosaicRefAcqTimes'),{slice_times_info.name});
slice_times = cell2mat(cellfun(@(x) str2num(x), {slice_times_info(slice_info_idx).item.val}, 'UniformOutput', false))/1e3;

testM = maskIDXs;
for j = 1:length(slice_times), testM(:,:,j) = j; end
slice_indices = testM(maskIDXs);
end

