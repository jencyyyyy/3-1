clc;
clear all;
close all;
n= -100:100;
alpha=.9;
xn=alpha.^n;
figure(1);
plot(n,xn);


%increasing

x= -10:100;
alpha=1.5;
fx=alpha.^x;
figure(2);
stem(x,fx);