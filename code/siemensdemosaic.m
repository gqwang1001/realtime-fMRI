% siemens demosaic 
% haris sair 6/17/2019
% Modified by Guoqing Wang 07/29/2020

function volume = siemensdemosaic(dicomfile)
    matrix = [1:64];
%     slicethickenss = 4;
    X=dicomread(dicomfile);
    X=im2double(X);
    volume=zeros(64,64,36);
    k = 1;
    for i = 1:6
        for j = 1:6
        volume(:, :, k) = X(matrix + (i-1) * 64, matrix + (j-1) * 64);
        k = k+1;
        end
    end
end

    