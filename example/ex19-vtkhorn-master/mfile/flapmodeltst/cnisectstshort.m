% function cnisectstshort
clear
% test intersection between line & cone
% - ONLY MINIMAL CALCULATIONS
% input parameters:
% 
% output parameters:
%
%
% USES:
%   none
% rolf mueller, 2007

% parameters: --------------------------------------------------

% height of flap cutting plane origin
fpch = 1;

% flap cutting plane normal:
%fpnx = rand;
%fpny = rand;
%fpnz = rand;

%fpnx = fpnx./sqrt(fpnx^2+fpny^2+fpnz^2);
%fpny = fpny./sqrt(fpnx^2+fpny^2+fpnz^2);
%fpnz = fpnz./sqrt(fpnx^2+fpny^2+fpnz^2);

% load coa, fca, fpnx, fpny, fpnz from file:
load /tmp/cnisectst.mat


% end parameters: -----------------------------------------------

% 1st intersecting line: 
% (goes through origin of flap cutting plane & flap center)
v1(1) = -fpnz*cos(fca);
v1(2) = -fpnz*sin(fca);
v1(3) =  fpnx*cos(fca)+fpny*sin(fca);

% 2nd intersecting line:
% (runs on cone surface, goes through origin & flap center)
v2(1) = cos(fca);
v2(2) = sin(fca);
v2(3) = cot(0.5*coa);

% cross product of direction vectors & its norm:
cp12(1) = v1(2)*v2(3)-v1(3)*v2(2);
cp12(2) = v1(3)*v2(1)-v1(1)*v2(3);
cp12(3) = v1(1)*v2(2)-v1(2)*v2(1);

cp12nrm2 = cp12(1)*cp12(1)+cp12(2)*cp12(2)+cp12(3)*cp12(3);

detval = fpch*(v2(2)*cp12(1)-v2(1)*cp12(2));

% distance from origin of flap cutting plane to flap center
s1 = detval./cp12nrm2;

fprintf('intersection: %f, %f, %f\n', ...
        s1*v1(1), ...
        s1*v1(2), ...
        fpch+s1*v1(3));
