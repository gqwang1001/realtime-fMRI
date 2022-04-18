function [X,dcmfile] = loadDICOM(i,tr, inds, workingdir, seriesID, studyID)


fname = sprintf('%03d_%06d_%06d.dcm', studyID, seriesID, inds(i)+1); % ['*' sprintf('%03d',inds(i)+1) '.dcm']

nextfile = strcat(workingdir, fname);
filename=dir(char(nextfile));

while isempty(filename)==1
    pause(tr)
    disp(['waiting ', num2str(tr),' seconds for next file']);
    filename=dir(char(nextfile));
end

dcmfile=dir(char(strcat(workingdir, fname)));
dcmfile = dcmfile(1);
dicomfile=dcmfile.name;

display(dicomfile)

%siemens demosaic function
X = siemensdemosaic(dcmfile.folder+"/"+dicomfile);
end

