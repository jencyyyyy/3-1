%quantanization to different bits
clc;
clear;
close all;

%quantanization
clc;
clear;
close all;

% analog signal x= 2*sin(2*pi*4*t)
figure(1);
a=10;
f=2;
t = 0:0.002:1; % 1/0.002 = 500 samples
main=a*sin(2*pi*f*t);
subplot(521);
plot(t,main);
title("Continuous sign wave");
xlabel("Continuous Time(t)");
ylabel("Amplitude");

%... Sampled sinewave
fsample = 60*f; %... Sampling frequency
n = 0:1/fsample :1; %... Sampled time
sampled = a*sin(2*pi*f*n);
subplot(522);
stem(n, sampled, ".");
hold on;
plot(t, main);
grid on;
title("Sampled sinwave");
xlabel("Time(n)");
ylabel("Amplitude");

%min and max
minimum = min(sampled);
maximum = max(sampled);


%figure(2);
%Quantanization
bit = 2;
step2 = (maximum-minimum)/2.^(bit);
quantanized2 = round(sampled/step2)*step2; %make integer
subplot(523);
plot(n,quantanized2);
hold on;
plot(t,main);
grid on;
title("Quantanized signal with 2 bits");
xlabel("Time(n)");
ylabel("Amplitude");

subplot(524);
qe2 = abs(round( quantanized2 -sampled));
stem(n,qe2,"b");




%figure(3);
%Quantanization
bit = 4;

step4 = (maximum-minimum)/2.^(bit);
quantanized4 = round(sampled/step4)*step4; %make integer
subplot(525);
plot(n,quantanized4);
hold on;
plot(t,main);
grid on;
title("Quantanized signal with 4 bits");
xlabel("Time(n)");
ylabel("Amplitude");

subplot(526);
qe4 = abs(round( quantanized4 -sampled));
stem(n,qe4);



%figure(4);
%Quantanization
bit = 8;

step8 = (maximum-minimum)/2.^(bit);
quantanized8 = round(sampled/step8)*step8; %make integer
subplot(527);
plot(n,quantanized8);
hold on;
plot(t,main);
grid on;
title("Quantanized signal with 8 bits");
xlabel("Time(n)");
ylabel("Amplitude");

subplot(528);
qe8 = abs(round( quantanized8 -sampled));
stem(n,qe8);

%figure(5);
%Quantanization
bit = 16;

step16 = (maximum-minimum)/2.^(bit);
quantanized16 = round(sampled/step16)*step16; %make integer
subplot(529);
plot(n,quantanized16);
hold on;
plot(t,main);
grid on;
title("Quantanized signal with 16 bits");
xlabel("Time(n)");
ylabel("Amplitude");

subplot(5,2,10);
qe16 = abs(round( quantanized16 -sampled));
stem(n,qe16);




