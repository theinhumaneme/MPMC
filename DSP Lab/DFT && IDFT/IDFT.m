clc;
clear all;
close all;
N = input('Enter total number of samples');
n = 0:1:N-1;
x = input('Enter the corresponding values of x');
k = 0:1:N-1;
wn = exp((-j*2*pi)./N);
kn = n'*k;
wk = wn.^kn;
Xk = (1/N)*x*wk;
mag = abs(Xk);
phase = angle(Xk)*(180/pi)
subplot(3,1,1);
stem(k,Xk);
xlabel('Frequency')
ylabel('Amplitude')
legend('19R11A04N1')
title('DFT Plot')
