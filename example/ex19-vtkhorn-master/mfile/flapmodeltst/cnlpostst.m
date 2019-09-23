% function cnlpostst
clear; clf;
% test canal position on pinna wall
% input parameters:
% 
% output parameters:
%
%
% USES:
%   none
% rolf mueller, 2007

coa = 30*pi/180;

% cylindrical coordinates of canal insertion point:
cnlh = .2;

cnla = 90*pi/180;

cnlhr = cnlh*tan(coa);

cnlix = cnlhr*cos(cnla);
cnliy = cnlhr*sin(cnla);

ah = axes;

lhs = line(2*[0 sin(coa)], 0*[1 1], 2*[0 cos(coa)], ...
           'Color', 'g');

lhi = line(cnlix, cnliy, cnlh, ...
           'Color', 'r', 'Marker', 'o');

set(ah, 'DataAspectRatio', [1 1 1]);

grid on;

xlabel('x');
ylabel('y');
zlabel('z');


view([1 0 0]);