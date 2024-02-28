A=1;
F=2;
t=0:0.01:1;
y= A*sin(2*pi*F*t);
subplot(2,1,1);
stem(t,y);%plot values
title('Sine wave');
z= A*cos(2*pi*F*t);
subplot(2,1,2);
plot(t,z);%only graph
title('Cosine wave');
