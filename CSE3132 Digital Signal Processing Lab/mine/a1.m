clc;
clear all;
close all;

t = 0:0.001:1; %1/0.001 = 1000 samples

f1=4;
f2=8;
f3=16;

amplitude1=10;
amplitude2=20;
amplitude3=40;
figure(1);
x1=  amplitude1*sin(2*pi*f1*t);
subplot(2,2,1);
plot(t,x1,'r');
%hold on;
x2 = amplitude2*sin(2*pi*f2*t);
subplot(2,2,2)
plot(t,x2,'b');
%hold on;
x3 = amplitude3*sin(2*pi*f3*t);
subplot(2,2,3)
plot(t,x3,'black');
%hold on;
x = x1+x2+x3
subplot(2,2,4);
plot(t,x,'g');
grid on;