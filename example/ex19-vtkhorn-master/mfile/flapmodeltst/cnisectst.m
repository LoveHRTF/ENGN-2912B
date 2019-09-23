% function cnisectst
clear
% test intersection between line & cone
% input parameters:
% 
% output parameters:
%
%
% USES:
%   none
% rolf mueller, 2007

% height of flap cutting plane origin
fpch = .5;

% flap cutting plane origin:
o1 = [0; 0; fpch];

% flap cutting plane normal:
fpnx = 0;
fpny = 0;
fpnz = 1;

fpnx = fpnx./sqrt(fpnx^2+fpny^2+fpnz^2);
fpny = fpny./sqrt(fpnx^2+fpny^2+fpnz^2);
fpnz = fpnz./sqrt(fpnx^2+fpny^2+fpnz^2);

% cone opening angle:
coa = 30*pi/180;

% angle of flap center:
fca = 0*pi/180;

% normal of vertical plane through origin & flap center:
vpnx = -sin(fca);
vpny = cos(fca);
vpnz = 0;

% orgin of vertical plane:
o2 = [0; 0; 0];

% direction vector of intersection line between the 2 planes:

%vi = cross([fpnx; fpny; fpnz], [vpnx; vpny; vpnz]);

vi = [fpny*vpnz-fpnz*vpny; ...
      fpnz*vpnx-fpnx*vpnz; ...
      fpnx*vpny-fpny*vpnx];

% 1st line to intersect: ----------------------------
pt1 = [0; 0; fpch]; % point on line

vd1 = vi; % direction vector

% 2nd line to intersect (line on cone surface): -----
pt2 = [0; 0; 0];

vd2 = [cos(fca); sin(fca); cot(0.5*coa)];


%cp12 = cross(vd1,vd2);
cp12= [vd1(2)*vd2(3)-vd1(3)*vd2(2); ...
       vd1(3)*vd2(1)-vd1(1)*vd2(3); ...
       vd1(1)*vd2(2)-vd1(2)*vd2(1)];

%cp12nrm = norm(cp12);
cp12nrm = sqrt(sum(cp12.^2));

m = [pt2'-pt1'; vd2'; cp12'];

detref = det(m);
dettst = m(1,1)*m(2,2)*m(3,3) ...
         -m(1,1)*m(2,3)*m(3,2) ...
         -m(1,2)*m(2,1)*m(3,3) ...
         +m(1,3)*m(2,1)*m(3,2) ...
         +m(1,2)*m(2,3)*m(1,3) ...
         -m(1,3)*m(2,2)*m(3,1);


s1 = dettst./cp12nrm.^2;

fprintf('intersection: %f, %f, %f\n', ...
        pt1(1)+s1*vd1(1), ...
        pt1(2)+s1*vd1(2), ...
        pt1(3)+s1*vd1(3));

% graphics: ---------------------------------------------
clf

scl = 2;

% origin of flap cutting plane:
lhpt1 = line(0, 0, fpch, 'Marker', '*');

% flap cutting plane:
sv1 = [0; fpnz; -fpny];
sv2 = cross(sv1, [fpnx; fpny; fpnz]);

pp1 = o1-sv1;
pp2 = o1+sv2;
pp3 = o1+sv1;
pp4 = o1-sv2;

phc = patch([pp1(1) pp2(1) pp3(1) pp4(1)], ...
            [pp1(2) pp2(2) pp3(2) pp4(2)], ...
            [pp1(3) pp2(3) pp3(3) pp4(3)], 'r');

set(phc, 'FaceAlpha', 0.5);

% plane through origin
sv1 = 2*[vpny; -vpnx; 0];
sv2 = 2*cross(sv1, [vpnx; vpny; vpnz]);

pp1 = o2-sv1;
pp2 = o2+sv2;
pp3 = o2+sv1;
pp4 = o2-sv2;

pho = patch([pp1(1) pp2(1) pp3(1) pp4(1)], ...
            [pp1(2) pp2(2) pp3(2) pp4(2)], ...
            [pp1(3) pp2(3) pp3(3) pp4(3)], 'b');

set(pho, 'FaceAlpha', 0.5);

% intersection line between planes:
line([pt1(1)-scl*vd1(1) pt1(1)+scl*vd1(1)], ...
     [pt1(2)-scl*vd1(2) pt1(2)+scl*vd1(2)], ...
     [pt1(3)-scl*vd1(3) pt1(3)+scl*vd1(3)], 'Color', 'r');

% cone surface line:
line([pt2(1)-scl*vd2(1) pt2(1)+scl*vd2(1)], ...
     [pt2(2)-scl*vd2(2) pt2(2)+scl*vd2(2)], ...
     [pt2(3)-scl*vd2(3) pt2(3)+scl*vd2(3)], 'Color', 'g');

% intersection point:

line([pt1(1)+s1*vd1(1)], ...
     [pt1(2)+s1*vd1(2)], ...
     [pt1(3)+s1*vd1(3)], 'Marker', 's', 'color', 'm', ...
     'MarkerSize', 10);
     
xlbl = xlabel('x');
ylbl = ylabel('y');
zlbl = zlabel('z');


view([0 0 1]);

axis equal
grid;

rotate3d on;

save /tmp/cnisectst.mat coa fca fpnx fpny fpnz
