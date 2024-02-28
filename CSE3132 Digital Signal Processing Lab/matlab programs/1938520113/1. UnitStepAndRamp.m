n=-10:1:10;
u =[zeros(1,10) ones(1,11)];

subplot(2,1,1);
stem(n,u);
axis([-10 10 -1 2]);
title("Unit Step");

m= -20:20;
ramp = (m>=0).*m;
subplot(2,1,2);
stem(m,ramp);
axis([-20 20 -10 20]);
title("Unit Ramp");
xlabel('Time sample');
ylabel('Amplitude');
