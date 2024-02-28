clc; %... Clear command line
clear all; %... Clear variables
close all; %... Clear figures

%... x = input("Enter the values of x");
%... h = input("Enter the values of h");
%... Input formet = [2 7 3 1 5]

h = [1 2 3 4]; %... Impulse response
x = [1 2 3 0]; %... Input sequence

z = []; %... To store values of x*h
for i = 1:length(x)
  xh = h.*x(i); %... Multiply x(i) with all values of h
  z = [z; xh]; %... Store xh in the next row of z
end

[r, c] = size(z); %... Row & column of z
ans = zeros(1,r+c-1); %... Convolution result will be stored here

for i = 1:r
  for j = 1:c
    ans(i+j-1) = ans(i+j-1)+z(i,j);
  end
end

z1 = 2; %... 0th index of x
z2 = 3; %... 0th index of h
index = (z1+z2-1); %... 0�th index of ans
n = -(index-1):length(ans)-index; %... time(n)
ans = conv(x,h);
disp(ans);
stem(n, ans, ".");
