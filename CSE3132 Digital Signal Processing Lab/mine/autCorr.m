clc;
clear all;
close all;

x=[1 2 3 4]
xInv = fliplr(x)
len = length(x);
z = [];

for k = 1:len
    row = xInv.*x(k);
    z = [z;row];
end

[r, c] =size(z);

answ = zeros(1,r+c-1);


for i= 1:r
    for j = 1:c
        answ(i+j-1) = answ(i+j-1)+z(i,j)
    end
end


n = - (len-1) : (len-1);
stem(n, answ);


