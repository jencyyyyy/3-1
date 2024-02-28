clc;
clear all;
close all;
figure(1);

x = 1:1:10;

y1 = 1:1:10;

subplot(2,2,1);
stem(x,y1);
y2 = [1 1 1 1 1 1 1 1 1 1];
subplot(2,2,2);
stem(x,y2);

x1=1:1:4;
a= 2;
y3 = a.^x1;

subplot(2,2,3);
plot(x1,y3);
