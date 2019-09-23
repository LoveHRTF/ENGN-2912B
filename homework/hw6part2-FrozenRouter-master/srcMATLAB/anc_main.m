% Adaptive Noise Canceller simulation

clear;
close all;
clc;

% load data
fd = fopen('../data/observed.dat','r');
s = fread(fd,'double');
fclose(fd);

fd = fopen('../data/noiseReference.dat','r');
nRef = fread(fd,'double');
fclose(fd);

Fs = 8192; % sampling frequency

% Play the observed signal
soundsc(s, Fs);
pause(5); % wait 5 seconds

% select the ANC algorithm
MODE = 'wiener';
% MODE = 'lms';

% set parameters
M = 100;
L = 500;
mu = .0075;

switch MODE
    case 'wiener'
        % compute the Wiener coefficients and perform filtering
        [e,w] = anc_wiener(s, nRef, M);   
        
    case 'lms'
        % iteratively estimate filter coefficients via LMS
        [e,w] = anc_lms(s, nRef, M, L, mu);
                
    otherwise
        error('Unknown MODE parameter')
end

% calculate mean square error (MSE)
MSE = e.^2;

% Play the filtered signal
soundsc(e, Fs);

% plot results
figure;
subplot(4,1,1)
plot(nRef); hold on;
set(gca,'YLim',[-3 3])
legend('nRef')
subplot(4,1,2)
plot(s)
set(gca,'YLim',[-3 3])
legend('s')
subplot(4,1,3)
plot(e)
set(gca,'YLim',[-.2 .2])
legend('e')
subplot(4,1,4)
plot(MSE,'m')
set(gca,'YLim',[0 .05])
legend('Mean Square Error')
set(gca,'YLim',[0 max(MSE(250:end))]);        % ignore initial error

% plot spectrograms
cLim = [-54 6];     % spectrogram limits
figure;
subplot(2,1,1)
spectrogram(s,hann(256),254,256,'yaxis'); colorbar;
xlabel('Time (samples)')
ylabel('Frequency (normalized)')
set(gca,'CLim',cLim);
subplot(2,1,2)
spectrogram(e,hann(256),254,256,'yaxis'); colorbar;
xlabel('Time (samples)')
ylabel('Frequency (normalized)')
set(gca,'CLim',cLim);