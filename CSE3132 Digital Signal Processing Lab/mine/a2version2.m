clc;
clear;
close all;

%sequesnce
xn = [1 8 4 3 0 8 2 10];
N= 8;

Xk = zeros(1,N);

for k=0:N-1
    Xk(k+1) = 0;
    for n=0:N-1
        Xk(k+1) = Xk(k+1)+ xn(k+1)*exp(-1i*2*pi*k*n/N);
    end
end

t=0:N-1;

subplot(311);
stem(t,xn);
title("Main Signal");

subplot(312);
stem(t, abs(Xk));
title("Magnitude plot");
xlabel('k');
ylabel('|X(k)|');

subplot(313);
stem(t,angle(Xk)); 
title('Phase plot');
xlabel('k');
ylabel('angle X(k)');


