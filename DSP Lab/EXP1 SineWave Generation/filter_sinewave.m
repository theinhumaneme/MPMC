% Sinewave using Recursive difference equation

clc;
clear all;
close all;
a = 0.13;
b = [1 -1.99 1];
n = 0:1:100;
x= zeros(1,length(n));
i = find(n>=0);
x(i)= 1;
y = filter(a,b,x)
subplot(1,1,1)
stem(n,y)
title('19R11A04N1')
legend('SinWave')
xlabel('Time')
ylabel('Amplitude')
