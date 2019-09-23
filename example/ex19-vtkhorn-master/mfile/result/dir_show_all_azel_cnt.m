% function dir_show_all_azel_cnt
% show a set of 2-dimensional directivity functions
% contour version
clear; clf
%
% input parameters:
% 
% output parameters:
%
%
% USES:
%   none
% rolf mueller, 2007

addpath('/usr/local/src/femmatlab');

% path to dir-files
DIRPATH='/usr/local/tmpdata/flapmodel';

% fixed parameters: ---------------------------------------------
T=20;

% angle file name:
ANG='az-180_1_180_el-90_1_90';

fang = [DIRPATH filesep ANG '.ang'];

[naz,azmin,azmax,daz,nel,elmin,elmax,del] = ang_read(fang);

% directivity normalization:
NRMFLG = 'nrm';

% variable parameters: ------------------------------------------
PRE= {'otc_12mm_noflap', 'otc_12mm_flap01'};

np = length(PRE);

fval = [30:10:120]; % 120 kHz

nf = length(fval);

for kp = 1:np

  for kf = 1:nf

    f = fval(kf);
  
    fdir = sprintf('%s_f%.2fkHzT%.2fC_%s_%s.dir', ...
                 PRE{kp}, f, T, NRMFLG, ANG);
    
    [gtmp,aztmp,neltmp] = dir_read([DIRPATH filesep fdir]);
    
    g(kf,kp,:,:) = gtmp;

  end % kf
end % kp

% graphics: ------------------------------------------


% map projection/parameters:
mp = defaultm('ortho');
mp.maplatlimit = [-90 90];
mp.maplonlimit = [-180 180];
mp.mlinelocation = 20; % single number: spacing
mp.plinelocation = 20; % single number: spacing
mp.mlinelimit = [-1 1]*80;
mp.grid = 'on';
mp.gcolor = [1 1 1]*.5;
mp.glinestyle = '-';
mp.glinewidth = 1;
mp.frame ='on';
mp.labelrotation = 'off'; % rotate grid text labels
mp.meridianlabel = 'off';
mp.parallellabel = 'off';
mp.labelformat = 'signed';
mp.fontsize = 12;
mp.mlabelparallel = 'equator';
%mp.plabelmeridian = mp.origin(2)+3*mp.plinelocation;
mp.falsenorthing = 0;
mp.falseeasting = 0;
mp.scalefactor = 1;
mp.origin = [45 0]; % [el az]

[az,el] = meshgrid(azmin:daz:azmax,elmin:del:elmax);
[xp,yp] = projfwd(mp, el, az);


cmap = jet(nf);

mrg = .1;
spc = .05;
gw = (1-2*mrg-(np-1)*spc)/np;

clf;

for kp = 1:np

  ah(kp) = axes('position', [mrg+(kp-1)*(gw+spc) mrg gw gw], ...
                'nextplot', 'add');
  hm(kp) = axesm(mp);
  
  th(kp) = title(PRE{kp});
  
  for kf = 1:nf
    
    [ch,hh(kf)] = contour(xp, yp, squeeze(g(kf,kp,:,:)), 1./sqrt(2), ...
                          'linewidth', 2);
  
    set(hh(kf), 'linecolor', cmap(kf,:));
  
  end % kf
  
end % kp

hold off;

set(gca, 'clim', [min(fval) max(fval)]);
colormap(cmap);
cbh = colorbar;
set(cbh, 'ytick', fval);

% reset position of axis with colorbar:
set(ah(np), 'position', [mrg+(np-1)*(gw+spc) mrg gw gw]);

set(ah, 'Visible', 'Off');
set(th, 'Visible', 'On');

set(th, 'FontSize', 8);
set(th, 'interpreter', 'none');
