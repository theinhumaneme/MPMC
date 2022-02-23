% SineWave using recursive function

% SineWave using recursive function

clc;
clear all;
close all;
I=input('Enter a prev value');
f=input('Enter frequency');
T=1/f;
n=0:T/f:T;
x=sin(2*3.14*f*n);
for i=1: length(n)
    y=x+I;
    I=y;
end
subplot(2,1,1);
stem(n,x);
xlabel('Frequency')
ylabel('Magnitude')
legend('19R11A04N1')
title('SineWave')

subplot(2,1,2);
stem(n,y);
xlabel('Frequency')
ylabel('Magnitude')
legend('19R11A04N1')
title('SineWave using recursive function')
