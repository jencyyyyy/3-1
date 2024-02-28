%sampling
% analog signal x= 2sin(2*pi*4*t)
clc;
clear;
close all;
figure(1);
%main signal
f=4;
a=2;
t=0:0.002:1; % 1/.002 = 500 samples

analog = a*sin(2*pi*f*t);



subplot(2,2,1);
hold on;
stem(t,analog,".");
%plot(t,analog,'r');
title("Analog sine signal");
xlabel("Continuous time");
ylabel("amplitude");

%Nyquist Rate =2*f

fn= 2*f;
nn= 0:1/fn:1;
nyquistSample = a*sin(2*pi*f*nn);

subplot(2,2,2);
hold on;
stem(nn,nyquistSample);
%plot(nn,nyquistSample);
title("Nyquist rate signal");
xlabel("sample");
ylabel("amplitude");

%Over sampling Rate fo>2fs

fo= 15*f;
no= 0:1/fo:1;
overSample = a*sin(2*pi*f*no);

subplot(2,2,3);
hold on;
stem(no,overSample,".");
%plot(no,overSample);
title("Over sampling rate signal");
xlabel("sample");
ylabel("amplitude");
hold on;

%Under sampling Rate fu<2f

fu= 0.7*f;
nu= 0:1/fu:1;
underSample = a*sin(2*pi*f*nu);

subplot(2,2,4);
hold on;
stem(nu,underSample,".");
%plot(nu,underSample);
title("Under sampling rate signal");
xlabel("sample");
ylabel("amplitude");

grid on;
hold on;
