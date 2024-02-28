clc;
clear; 
close;

%... Discrete Fourier Transform

xInput = [1 2 3 4 5 6 7 8];
N = length(xInput); %... How many point dft
n = 0:N-1; %... Time(n)
xLength = length(xInput);
subplot(2,1,1);
stem(n, xInput, ".");

xD = zeros(1,N);

for k = 0:N-1
  for n = 0:N-1
    xD(k+1) = xD(k+1)+xInput(n+1)*exp(-1i*2*pi*k*n/N);
  end
end

%... Inverse Discrete Fourier Transform
xInv = zeros(1,N);

for k = 0:N-1
  for n = 0:N-1
    xInv(k+1) = xInv(k+1)+xD(n+1)*exp(1i*2*pi*n*k/N);
  end
  xInv(k+1) = xInv(k+1)/N;
end

%... Ploting Inverse DFT
n = 0:N-1;
subplot(2,1,2);
stem(n, xInv, ".");
title("IDFT");
