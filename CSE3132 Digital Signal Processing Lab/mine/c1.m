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
subplot(311);
plot(t,main);
title("Continuous sign wave");
xlabel("Continuous Time(t)");
ylabel("Amplitude");

%... Sampled sinewave
fsample = 60*f; %... Sampling frequency
n = 0:1/fsample :1; %... Sampled time
sampled = a*sin(2*pi*f*n)
subplot(312);
stem(n, sampled, ".");
hold on;
plot(t, main);
grid on;
title("Sampled sinwave");
xlabel("Time(n)");
ylabel("Amplitude");


%Quantanization
bit = 3;
minimum = min(sampled);
maximum = max(sampled);
step = (maximum-minimum)/2.^(bit);
quantanized = round(sampled/step)*step %make integer
subplot(313);
plot(n,quantanized);
hold on;
plot(t,main);
grid on;
%axis([-1 2 -3 3]);
title("Quantanized signal");
xlabel("Time(n)");
ylabel("Amplitude");






