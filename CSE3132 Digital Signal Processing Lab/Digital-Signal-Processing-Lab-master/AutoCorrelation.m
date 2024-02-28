clc; %... Clear command line
clear; %... Clear variables
close all; %... Clear figures

%... x = input('Enter the first sequence');
%... Input Formet: [1 3 7 4 9 5]

x = [1 2 3 4];
xNeg = fliplr(x);

z = [];
for i = 1:length(x)
  temp = xNeg.*x(i);
  z = [z;temp];
end

[r, c] = size(z);
ans = zeros(1,r+c-1);

for i = 1:r
  for j = 1:c
    ans(i+j-1) = ans(i+j-1)+z(i,j)
  end
end

disp(ans);
n = -(length(xNeg)-1):length(x)-1;
stem(n, ans, ".");


