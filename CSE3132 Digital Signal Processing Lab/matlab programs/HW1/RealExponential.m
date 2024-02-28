clc;
clear;
close all;

x = -1:0.1:1;
sigma=2;
y1 = exp(sigma*x);
%stem(x,y1);
%figure(1);
subplot(3,1,1);
plot(x,y1);
title('Real Exp. Signal (increasing)');
xlabel('time');
ylabel('x(t)');

%Decreasing
sig=-2;
y2 = exp(sig*x);
%figure(2);
subplot(3,1,2);
plot(x,y2);
title('Real Exp. Signal (Decreasing)');
xlabel('time');
ylabel('x(t)');


%Both increasing and decreasing in one figure
%figure(3);
subplot(3,1,3);
plot(x,y1,'r',x,y2,'g','LineWidth',2.5);
xlabel('time');
ylabel('x(t)');
