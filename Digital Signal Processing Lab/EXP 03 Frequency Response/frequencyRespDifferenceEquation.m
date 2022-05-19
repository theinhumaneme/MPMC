



numeratorCoeff = input('Enter the values for Numerators');
denominatorCoeff = input('Enter the values for Denominators');
samplingFreq = ('Enter the sampling Frequency');
w = 0:(2*pi)/frequencySamples:(2*pi);
l = 0:length(numeratorCoeff)-1;
m = 0:length(denominatorCoeff)-1;
N = numeratorCoeff*exp(-j*l'*w);
D = denominatorCoeff*exp(-j*m'*w);
H = N./D;
magnitude = abs(H);
phase = angle(H);
subplot(2,1,1);
normalizedFrequency = w/(2*pi);
subplot(2,1,1)
plot(normalizedFrequency,magnitude)
title('Exp3 Frequency Reponse using Difference Equations')
legend('Magnitude Plot')
xlabel('Frequency')
ylabel('Amplitude')
subplot(2,1,2)
plot(normalizedFrequency,phase)
legend('Phase Plot')
xlabel('Time')
ylabel('Frequency')

% Sample Input
% numeratorCoeff = [1]
% denominatorCoeff = [1 -1*0.9]