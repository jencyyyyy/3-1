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

if(nPoint < xLength)
  error("Can not perform dft. Point should be >= length");
end

xInput = [xInput zeros(1,nPoint-xLength)];

for k = 0:nPoint-1
  xD(k+1) = 0;
  for n = 0:nPoint-1
    xD(k+1) = xD(k+1)+xInput(n+1)*exp(-1i*2*pi*k*n/nPoint);
  end
end

%... Ploting magnitude
n = 0:nPoint-1;
subplot(3,2,2);
plot(n, abs(xD));
axis tight;
title("Magnitude spectrum");

%... Ploting phase
n = 0:nPoint-1;
subplot(3,2,3);
plot(n, angle(xD));
axis tight;
title("phase spectrum");

%... Inverse Discrete Fourier Transform

for k = 0:nPoint-1
  xInv(k+1) = 0;
  for n = 0:nPoint-1
    xInv(k+1) = xInv(k+1)+xD(n+1)*exp(i*2*pi*n*k/nPoint);
  end
  xInv(k+1) = xInv(k+1)/nPoint;
end

%... Ploting Inverse DFT
n = 0:nPoint-1;
subplot(3,2,4);
stem(n, xInv, ".");
title("IDFT");
axis tight;

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
