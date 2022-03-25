% TO FIND FREQUNCY RESPONSE OF A GIVEN SYSTEM FROM TRANSFER FUNCTION OR
% DIFFERENTIAL EQUATION FORM

frequencySamples = input('Enter the number of Frequency Samples');
w = 0:(2*pi)/frequencySamples:(2*pi);

% H = zeros(1,length(w));
% for i=1:length(w)
%     H(i) = (1)/(1-0.9*exp(-1*j*w(i)));
% end


H = (1)./(1-0.9*exp(-1*j*w));
magnitude = abs(H);
phase = angle(H);
subplot(2,1,1);
normalizedFrequency = w/(2*pi);
subplot(2,1,1)
plot(normalizedFrequency,magnitude)
title('Exp3 Frequency Reponse using Transfer Function')
legend('Magnitude Plot')
xlabel('Frequency')
ylabel('Amplitude')
subplot(2,1,2)
plot(normalizedFrequency,phase)
legend('Phase Plot')
xlabel('Time')
ylabel('Frequency')

% Sample Input
% frequencySamples = 200 <Your Choice>
