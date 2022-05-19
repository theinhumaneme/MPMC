clc;
close all;

wp = input('Enter Pass Band Frequency'); % 0.3*pi
ws = input('Enter Pass Band Frequency'); % 0.1*pi

tb = wp-ws;

wc = (wp+ws)/2;

N = ceil((6.6*pi)/tb);

n = 0:N-1;

alpha = (N-1)/2;

for i =0:N-1
    if i == alpha
        hd(i+1) = 1 - (wc/pi);
    else
        hd(i+1) = (sin(pi*(i - alpha)) - sin(wc*(i-alpha)))/pi*(i- alpha);
    end
end

% WINDOE TECHNIQUE

wi = hamming(N);
h = hd.*wi';
a =  [h(alpha +1) 2*h(alpha:-1:1)]';
w1 = input('Enter Number of Frequnecy Points'); %100

w = (0:w1)'*(pi/w1);

n1 = 0:alpha;

hr = cos(w*n1)*a;
mag = abs(hr);
phase = angle(hr);

subplot(2,3,1)
stem(n,hd);
xlabel('Time')
ylabel('Magnitude')
title('Hd')
grid

subplot(2,3,2)
stem(n,wi);
xlabel('Time')
ylabel('Magnitude')
title('Hamming Window')

subplot(2,3,3)
stem(n,h);
xlabel('Time')
ylabel('Magnitude')
title('Finite Response')

subplot(2,3,4)
stem(w,mag)
title('Magnitude Plot')

subplot(2,3,5)
stem(w,phase)
title('Phase plot')
