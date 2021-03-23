function pars = motionPar(tform)
% Calculate six motion parameters
% INPUT affine3d object.
% OUTPUT: six motion parameters:
% [translation_x, translation_y, translation_z, yaw, pitch, roll].
% Created by Guoqing Wang, 08/03/2020.

xyzt = tform.T(4, 1:3);

a = atan(tform.T(1,2)/tform.T(1,1));
b = atan(tform.T(2,3)/tform.T(3,3));
c = atan(-tform.T(1,3)/sqrt(tform.T(2,3)^2 + tform.T(3,3)^2));

pars = [xyzt, a,b,c];

end