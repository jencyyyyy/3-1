clc;
clear all;
close all;

x=[1 2 3 4]
y = [1 2 3]
yFlip = fliplr(y);

len = length(x);
z = [];

for k = 1:len
    row = yFlip.*x(k);
    z = [z;row];
end

[r, c] =size(z);

answ = zeros(1,r+c-1);


for i= 1:r
    for j = 1:c
        answ(i+j-1) = answ(i+j-1)+z(i,j)
    end
end

w = length(answ)

n = - (length(y)-1) : (length(x)-1);
stem(n, answ);

disp(answ);



