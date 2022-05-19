clc;
close all;
ap = 0.4;
as = 30;
fp = 800;
fs = 300;
f = 2000;

omp = (2*fp)/f;
oms = (2*fs)/f;

[n, wn] = buttord(omp,oms,ap,as);
[b, a] = butter(n,wn,'HIGH');

w = 0:0.01:pi;

[h, om] = freqz(b,a,w);
subplot(2,1,1)
plot((om/pi), 20*log10(abs(h)));
title('Magnitude Response');
xlabel('Frequency');
ylabel('gain in dB');
grid
subplot(2,1,2)
plot((om/pi),angle(h))
title('Phase Response');
xlabel('Frequency');
ylabel('Phase');
grid