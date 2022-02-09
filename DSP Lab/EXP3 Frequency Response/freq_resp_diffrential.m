% frequency response of Transfer Function using diffrential equaation
% coeffcients

clc;
clear all;
close all;
n = 0:0.1:2*pi;
a = input('Enter A input Coeffcients');
b = input('Enter B input Coeffcients');
len1 = 0:length(a)-1
len2 = 0:length(b)-1
tf1 = a*exp(-i*len1'*n)
tf2 = b*exp(-i*len2'*n)
h = tf1./tf2
mag = abs(h)
phase = angle(h)
subplot(2,1,1)
plot(n/pi,mag)
title('19R11A04N1 ')
legend('Magnitude Response')
xlabel('Frequency')
ylabel('Amplitude')
subplot(2,1,2)
plot(n/pi,phase)
legend('Phase Response')
xlabel('Frequency')
ylabel('Phase')