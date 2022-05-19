%DIF_FFT
clc;
clear all;
close all;
x = input('Enter a Sequence = '); 
n = input('Enter Time instance = ');
N = input('Enter a N - point DFT = '); 
if length(x)<N
    x = [x zeros(1,N-length(x))];
    n = [n max(n)+1:N-1];
end

M = log2(N);

for m = 1:M
    s = 2^(M-m+1);
    for l =1:s:(N-1)
        for k = 0:(s/2)-1
            Wn = exp(-j*2*pi*(k/s));
            Z1 = x(l+k);
            Z2 = x(l+k+s/2);
            x(l+k)=Z1+(Z2*Wn);
            x(l+k+s/2)=Z1-(Z2*Wn);
        end 
    end
end
y = bitrevorder(x)