clc;
clear all;
close all;

x=[1 2 3 4]
xInv = fliplr(x);

z=[];

for k = 1:length(x)
    tem = xInv.*x(1);
    z = [z;temp]
end