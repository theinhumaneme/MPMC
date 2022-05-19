f1 = input('Enter the frequnecy of first Signal');
f2 = input('Enter the frequnecy of first Signal');
S = input('Enter the number of Samples');
n = 0:S-1;

%Generate Sinusodial Signal
x = cos(pi*f1*n) + cos(pi*f2*n);

%Number of Samples
samples_x = input('Enter the number of samples of Signal X to be Considered');

n1 = 0:samples_x-1;

% Sampled Signal
sampled_x = x(1:samples_x);

DFT_len = input('Enter the length of DFT');
K = 0:DFT_len-1;

%GENERATE THE FFT SIGNAL
X = fft(sampled_x,DFT_len);

power_spectrum_density = (1/DFT_len)*abs(X).^2;

%PLOTTING ON A 2X2 MAT
subplot(2,2,1)
plot(n,x);
xlabel('Time');
ylabel('Amplitude');
title('Sinusodial Input')

subplot(2,2,2)
plot(n1,sampled_x);
xlabel('Time');
ylabel('Amplitude');
title('Sampled Signal')

subplot(2,2,3)
plot(K*(2/DFT_len),power_spectrum_density);
xlabel('Time');
ylabel('Amplitude');
title('Power Spectrum Density')

subplot(2,2,4)
plot(K*(2/DFT_len),10*log(power_spectrum_density));
xlabel('Time');
ylabel('Amplitude');
title('10*log(PSD)')
