function [X,dcmfile] = loadDICOM(i,tr, inds, workingdir)

nextfile = workingdir+['*' sprintf('%03d',inds(i)+1) '.dcm'];
filename=dir(nextfile);

while isempty(filename)==1
    pause(tr)
    disp(['waiting ', num2str(tr),' seconds for next file']);
    filename=dir(nextfile);
end

dcmfile=dir(workingdir+['*' sprintf('%03d',inds(i)) '.dcm']);
dcmfile = dcmfile(1);
dicomfile=dcmfile.name;

display(dicomfile)

%siemens demosaic function
X = siemensdemosaic(dcmfile.folder+"/"+dicomfile);
end

