% function dir_show_all_azel_srf
% show a set of 2-dimensional directivity functions
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
PRE= {'otc_12mm_noflap'};

np = length(PRE);

fval = [80:10:120]; % kHz

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


% map projection:
mp = defaultm('ortho');

[az,el] = meshgrid(azmin:daz:azmax,elmin:del:elmax);

mp.origin = [45 0]; % [el az]
[xp,yp] = projfwd(mp, el, az);

kg=1; % count graphs

for kf = 1:nf
  for kp = 1:np
    ah(kf,kp) = subplot(nf, np, (kf-1)*np+kp);
    
    mapshow(xp, yp, squeeze(g(kf,kp,:,:)), 'DisplayType', 'surface');

    if (kf==1)
      th(kp) = title(PRE{kp});
    end
    
    if (kp==1)
      ylbl(kf) = ylabel(sprintf('%.1f kHz', fval(kf)));
    end
      
    kg = kg+1;
  end % kp
end % kf

%cbh = colorbar;


set(ah, 'Visible', 'Off');
set([ylbl(:); th(:)], 'Visible', 'On');

set(th, 'FontSize', 8);
set(th, 'interpreter', 'none');
