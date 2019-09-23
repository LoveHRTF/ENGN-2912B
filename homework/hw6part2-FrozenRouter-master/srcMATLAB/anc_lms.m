function [e, w, w_hat, y] = anc_lms(d, x, M, L, mu)
% ANC_LMS  Adaptive noise canceller using Least Mean Square minimization
%
% The LMS algorithm converges to the Wiener filter coefficients and adapts to
% changes in the noise statistics.

N = length(x);

% estimate LMS learning coefficient, if not specified
if ~exist('mu','var')
    rxx = xcorr(x,L,'biased');
    
    % use autocorrelation peak (fastest approach)
    mu = 2/(3 * M * rxx(L+1));
    mu = mu/2;  % cut mu down
    fprintf('Setting mu = %g\n',mu)
    
    clear rxx Rxx
end

% preallocate arrays
w = zeros(M,1);
y = zeros(N,1);
e = zeros(N,1);
w_hat = zeros(M,N);

% iterativly filter data while updating coefficients
for n=M:N
    x1 = x(n:-1:n-M+1);     % update reference data with sliding window
    
    y(n) = w.'*x1;            % generate next data sample - M mults
    e(n) = d(n)-y(n);       % Subtract filtered noise reference from signal - M subtractions
    w = w + 2 * mu * e(n) * x1;    % Update coefficients - M additions, 2*M mults
    
    w_hat(:,n) = w;         % save history of filter coefficients
end