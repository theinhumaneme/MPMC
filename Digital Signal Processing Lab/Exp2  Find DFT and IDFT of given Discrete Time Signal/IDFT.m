nPointDFT = input('Enter the N-point IDFT to be calculated');
n = 0:1:nPointDFT-1;
dftSequence = input('Enter the Input FFT Sequence');

% if the Input Sequence != N-Point Implement Zero Padding
if (length(dftSequence)<nPointDFT)
    dftSequence([length(dftSequence)+1:nPointDFT]) = zeros(1,nPointDFT-length(dftSequence));
end

k = 0:1:nPointDFT-1;
wn = exp((-1*j*2*pi)./nPointDFT);


kn = n'*k;
Z = wn.^kn;
% X = (1/nPointDFT)*dftSequence.*Z;
X = (1/nPointDFT)*dftSequence*Z;
mag = abs(X);
phase = angle(X)*(180/pi)
subplot(3,1,1);
stem(x,n);
xlabel('Frequency')
ylabel('Amplitude')
legend('19R11A04N1')
title('IDFT Plot')
subplot(3,1,2);
stem(k,mag);
xlabel('Frequency')
ylabel('Magnitude')
legend('19R11A04N1')
title('Magnitude Plot of IDFT')
subplot(3,1,3);
stem(k,phase)
xlabel('Frequency')
ylabel('Phase')
legend('19R11A04N1')
title('Phase Plot of IDFT')

% Sample Input
% N-Point DFT = 8
% FFT Sequence = [1 3 4 5 6 0 0 0]