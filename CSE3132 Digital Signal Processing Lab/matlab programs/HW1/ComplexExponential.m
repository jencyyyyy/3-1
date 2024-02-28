t =linspace(0,2.5,250);
A=1;
sig=2; %-2 dile decay hobe
frequency=2;
f = A*exp((sig+2*pi*frequency*1i)*t);
figure(1);
plot3(t,real(f),imag(f),'lineWidth',2)
figure(2)
plot(t,real(f),'lineWidth',2)
figure(3)
plot(t,imag(f),'lineWidth',2)