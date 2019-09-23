% function cnldirtst
clear; clf;
% test canal position
% input parameters:
% 
% output parameters:
%
%
% USES:
%   none
% rolf mueller, 2007

DEG2RAD = pi/180;

cnla = 25;

coa = 20;

cnlh = 0.5;

% canal insertion point on pinna:
cnlhr = cnlh*tan(coa*DEG2RAD);
cnlix = cnlhr*cos(cnla*DEG2RAD);
cnliy = cnlhr*sin(cnla*DEG2RAD);

% target canal axis vector:
cavx = cos(cnla*DEG2RAD);
cavy = sin(cnla*DEG2RAD);
cavz = -sin(coa*DEG2RAD);

% normalize
cavn = sum(cavx.^2+cavy.^2+cavz.^2);
cavx = cavx/cavn;
cavy = cavy/cavn;
cavz = cavz/cavn;

% original canal (cylinder) axis vector:
ccvx = 0;
ccvy = 1;
ccvz = 0;

% angle between the cav & ccv:
crotang = acos((cavx*ccvx+cavy*ccvy+cavz*ccvz));

% rotation axis vector (normal to both cav & ccv):
% for rotating cylinder axis vector into target canal axis vector
crvx = cavy*ccvz - cavz*ccvy;
crvy = cavz*ccvx - cavx*ccvz;
crvz = cavx*ccvy - cavy*ccvx;

crvn = sqrt(sum(crvx^2+crvy^2+crvz^2));
crvx = crvx./crvn;
crvy = crvy./crvn;
crvz = crvz./crvn;

% rotation matrix to rotate cylinder axis to target axis:
% (right-handed)
% http://www.cprogramming.com/tutorial/3d/rotation.html
c = cos(crotang);
s = sin(crotang);
t = 1-cos(crotang);

Mr = [t*crvx^2+c t*crvx*crvy+s*crvz t*crvx*crvz-s*crvy; ...
      t*crvx*crvy-s*crvz t*crvy^2+c t*crvy*crvz+s*crvx; ...
      t*crvx*crvy+s*crvy t*crvy*crvz-s*crvx t*crvz^2+c];

Ml = [t*crvx^2+c t*crvx*crvy-s*crvz t*crvx*crvz+s*crvy; ...
      t*crvx*crvy+s*crvz t*crvy^2+c t*crvy*crvz-s*crvx; ...
      t*crvx*crvy-s*crvy t*crvy*crvz-s*crvx t*crvz^2+c];

% FIXME: Mr, Ml give a (slightly) wrong result

% graphics: --------------------------------------------------

ah(1) = subplot(1,2,1);

t = linspace(0, 2*pi, 100);

plot(cnlhr*cos(t), cnlhr*sin(t), 'b-', cnlix, cnliy, 'mo', ...
     cnlix+[0 cavx], cnliy+[0 cavy], 'r-');


ah(2) = subplot(1,2,2);

plot([0 -sin(coa*DEG2RAD)], ...
     [0 cos(coa*DEG2RAD)], 'g-', ...
     [0  sin(coa*DEG2RAD)], ...
     [0 cos(coa*DEG2RAD)], 'g-', ...
     cnlhr, cnlh, 'mo', ...
     cnlhr+[0 1], cnlh+[0 cavz], 'r-');

set(ah, 'DataAspectRatio', [1 1 1]);