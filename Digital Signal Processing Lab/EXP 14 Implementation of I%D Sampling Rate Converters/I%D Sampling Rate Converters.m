vals = input('Enter the input Sequence');
L = input('Enter the length of the sequence');
I = input('Enter the inteprolation factor');
N = 1:L;
j =1;

% PREALLOCATE MEMORY IN ADVANCE (PERF OPTIMIZATIONS)
y = zeros(1,L*I);

%Interpolate
for i=1:L
    y(j) = vals(i);
    j = j+I;
end
%length of the interpol sequence
interpol = 1:length(y);

D = input('Enter Decimation Factor');

% Decimate
M = y(1:D:length(y));

%length of the decimated sequence
deci = 1:length(M);

% GIVEN SEQ
subplot(3,1,1)
stem(N,vals);
xlabel('Time')
ylabel('Amplitude')
legend('Given SEQ')

%INTERPOLATED SEQ
subplot(3,1,2)
stem(interpol,y);
xlabel('Time')
ylabel('Amplitude')
legend('Interpolated SEQ')

%DECIMATED SEQ
subplot(3,1,3)
stem(M,deci);
xlabel('Time')
ylabel('Amplitude')
legend('Decimated SEQ')
