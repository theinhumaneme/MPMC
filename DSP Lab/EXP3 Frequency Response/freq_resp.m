% Frequency Response of a system from transfer function

% z = cos(w)+ jsin(w)
% y[n] = 0.5y[n-1] = x[n]
% y[z] - 0.5*z^1*y[z] = x[z]
% h[z] = y[z]/x[z] => 1/(1 - 0.5*z^-1)

clc;
clear all;
close all;
w = 0:0.1:2*pi
y = 1./(1-0.9*((exp(-1*i*(w)))))
mag = abs(y)
phase = angle(y)
subplot(2,1,1)
plot(w,mag)
title('19R11A04N1 ')
legend('Magnitude Response')
xlabel('Frequency')
ylabel('Amplitude')
subplot(2,1,2)
plot(w,phase)
legend('Phase Response')
xlabel('Frequency')
ylabel('Phase')