% function lintersectst
clear
%
% input parameters:
% 
% output parameters:
%
%
% USES:
%   none
% rolf mueller, 2007

coa = rand*85*pi/180;

cpna = -60*pi/180;

cpch = 1;

x1 = 0;
z1 = 0;

x2 = sin(coa/2);
z2 = cos(coa/2);

x3 = 0;
z3 = cpch;

x4 = sin(cpna);
z4 = cpch+cos(cpna);



%ua = ((x4-x3)*(z1-z3)-(z4-z3)*(x1-x3))./((z4-z3)*(x2-x1)-(x4-x3)*(z2-z1));

ua = (z3*x4)./(x4*z2-(z4-z3)*x2);


%ua=(cpch*sin(cpna))./(sin(cpna)*cos(coa/2)-cos(cpna)*sin(coa/2));
ua1=(cpch*sin(cpna))./sin(cpna-coa/2);
ua2=(cpch*sin(cpna))./sin(cpna+coa/2);

%xi = x1 + ua*(x2-x1);
%zi = z1 + ua*(z2-z1);

%xi1 = ua1*sin(coa/2);
%zi1 = ua1*cos(coa/2);

%xi2 = ua2*sin(-coa/2);
%zi2 = ua2*cos(coa/2);

xi1 = (cpch*sin(cpna)*sin(coa/2))./sin(cpna-coa/2);
zi1 = (cpch*sin(cpna)*cos(coa/2))./sin(cpna-coa/2);

xi2 = -(cpch*sin(cpna)*sin(coa/2))./sin(cpna+coa/2);
zi2 = (cpch*sin(cpna)*cos(coa/2))./sin(cpna+coa/2);


% graphics: --------------------------------------------------

plot(xi1, zi1, 'm*', xi2, zi2, 'm*');

scl = 5;

lhpw1 = line([x1 x2], [z1 z2], 'Marker', 'o', 'LineStyle', ...
             'none', 'Color', 'r');

lhpw2 = line(-[x1 x2], [z1 z2], 'Marker', 'o', 'LineStyle', ...
             'none', 'Color', 'r');

lhpc = line([x3 x4], [z3 z4], 'Marker', 'o', 'LineStyle', ...
             'none');


xmin = min([x1 x2 x3 x4 xi1]);
xmax = max([x1 x2 x3 x4 xi1]);

xmrg = 0.1*(xmax-xmin);

mw1 = (z2-z1)/(x2-x1);
mw2 = (z2-z1)/(x1-x2);
mc = (z4-z3)/(x4-x3);

bw1 = z1-mw1*x1;
bw2 = z1-mw2*x1;
bc = z3-mc*x3;

lhw1 = line([xmin-xmrg xmax+xmrg], mw1*[xmin-xmrg xmax+xmrg]+bw1, ...
           'Color', 'r');
lhw2 = line([xmin-xmrg xmax+xmrg], mw2*[xmin-xmrg xmax+xmrg]+bw2, ...
           'Color', 'r');

lhc = line([xmin-xmrg xmax+xmrg], mc*[xmin-xmrg xmax+xmrg]+bc);