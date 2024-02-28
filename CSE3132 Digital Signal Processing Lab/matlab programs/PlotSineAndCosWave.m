A=2;
f=2;
t=0:0.01:1;
xt = A*sin(2*pi*f*t);
x2t = A*cos(2*pi*f*t);
figure(1);
subplot(2,1,1);
plot(t,xt);
subplot(2,1,2);
plot(t,x2t);


