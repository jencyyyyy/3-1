clc; %... Clear command line
clear all; %... Clear variables
close all; %... Clear figures

n = 0:1/80:1; %... Sampling frequency = 80 Hz
h = 5*sin(2*pi*4*n);
x = 7*sin(2*pi*3*n);

z = []; %... To store values of x*h
for i = 1:length(x)
  xh = h.*x(i); %... Multiply x(i) with all values of h
  z = [z; xh]; %... Store xh in the next row of z
end

[r, c] = size(z); %... Row & column of z
answ = zeros(1,r+c-1); %... Convolution result will be stored here

for i = 1:r
  for j = 1:c
    answ(i+j-1) = answ(i+j-1)+z(i,j);
  end
end

z1 = 2; %... 0�th index of x
z2 = 3; %... 0�th index of h
index = (z1+z2-1); %... 0�th index of ans
n = -(index-1):length(answ)-index; %... time(n)

disp(answ);
plot(n, answ);
