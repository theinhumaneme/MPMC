T =1;
fs = input('Sampling Freq'); % 10 or 100
n = 0: T/fs:10;
x = zeros(1,length(n));
i = find(n==0)
x(i) =1;
a = input('Enter the I/P Coeff'); % [1]
b = input('Enter the O/P Coeff'); % [1 -0.9 -1]
y = filter(a,b,x);
subplot(2,1,1)
stem(n,x);
title('Impulse Response of First Order System');
xlabel('time');
ylabel('Amplitude');

subplot(2,1,2)
stem(n,y);
title('Impulse Response of Second Order System');
xlabel('time');
ylabel('Amplitude');
