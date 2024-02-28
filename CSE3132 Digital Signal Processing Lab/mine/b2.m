clc; %... Clear command line
clear all; %... Clear variables
close all; %... Clear figures

%... Discrete Fourier Transform

xInput = [1 2 3 4 5 6 7 8];
nPoint = length(xInput); %... How many point dft
n = 0:nPoint-1; %... Time(n)
xLength = length(xInput);
subplot(3,2,1);
stem(n, xInput, ".");

for k = 0:nPoint-1
  xD(k+1) = 0;
  for n = 0:nPoint-1
    xD(k+1) = xD(k+1)+xInput(n+1)*exp(-1i*2*pi*k*n/nPoint);
  end
end
disp(xD);
%... Time shifting property
m = 2;
for k = 0:nPoint-1
  xD(k+1) = xD(k+1)*exp(-i*2*pi*k*m/nPoint);
end

for k = 0:nPoint-1
  xInv(k+1) = 0;
  for n = 0:nPoint-1
    xInv(k+1) = xInv(k+1)+xD(n+1)*exp(i*2*pi*n*k/nPoint);
  end
  xInv(k+1) = xInv(k+1)/nPoint;
end

%... Ploting shifted Inverse DFT
n = 0:nPoint-1;
subplot(3,2,5);
stem(n, xInv, ".");
axis tight;
title("Time shift");
