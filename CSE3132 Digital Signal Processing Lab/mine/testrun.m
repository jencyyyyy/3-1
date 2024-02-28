clc;
clear;
close all;

%sequesnce
%xn = input('Enter the sequence');
xn = [1 2 3];
%N = input('Enter no. of samples, N= ');
N= 8;
L =length(xn);

%for input taken from user check if n
 if(N<L)
    error('N should not be less than L');
 end
% 
 xn = [xn zeros(1,N-L)];
%X1 = [zeros(1,N-1);zeros(1,N-1)];

for k=0:N-1
    for n=0:N-1
        Wn = exp(-1i*2*pi*k*n/N);
        X1(k+1,n+1) = Wn;
    end
end

Xk = X1*xn'; % xn' means transpose of xn

t=0:N-1;
subplot(222);
stem(t, abs(Xk));
title("Magnitude plot");
xlabel('k');
ylabel('|X(k)|');

subplot(2,2,4);
stem(t,angle(Xk)); 
title('Phase plot');
xlabel('k');
ylabel('angle X(k)');






