vals = input('Enter the input Sequence');
L = input('Enter the length of the sequence');
N = 1:L;
D = input('Enter Decimation Factor');

% Decimate
M = vals(1:D:length(vals));

%length of the decimated sequence
deci = 1:length(M);

% GIVEN SEQ
subplot(3,1,1)
stem(N,vals);
xlabel('Time')
ylabel('Amplitude')
legend('Given SEQ')
title('Given Sequence')

%DECIMATED SEQ
subplot(3,1,3)
stem(M,deci);
xlabel('Time')
ylabel('Amplitude')
legend('Decimated SEQ')
title('Decimated SEQ')
