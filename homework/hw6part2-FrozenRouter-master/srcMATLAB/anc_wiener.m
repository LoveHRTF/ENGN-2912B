function [e, w, y] = anc_wiener(d, x, M)
% ANC_WIENER  Adaptive noise canceller using Wiener filtering
%
% The Wiener filter is optimal in MSE sense, but requires a WSS assumption.
%
% The Wiener filter automatically corrects for the delay by detecting the time
% shift in the crosscorrelation sequence and adjusting the group delay of the
% filter.  The magnitude is also adjusted to correct for the difference in noise
% amplitudes.  This appears to be extremely effective for a scaled and delayed
% version of the reference noise signal.

% compute noise statistics
Rxx = xcorr(x, M, 'biased');
Rxx = Rxx(M+1:M+M);
Rxx = toeplitz(Rxx);

rdx = xcorr(d, x, M, 'biased');
rdx = rdx(M+1:M+M);

% compute Wiener filter coefficients
w = inv(Rxx)*rdx;

% filter reference noise sequence and subtract from signal
y = fftfilt(w,x);
e = d - y;