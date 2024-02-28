t= -2:0.1:2;
sigma = 2; %Increasing order
x= exp(t*sigma);
subplot(2,1,1);
stem(t,x);
title("Real Exponent (increasing order)");
xlabel("time");
ylabel("x(t)");

t= -2:0.1:2;
sigma = -2; %Putting negative value of sigma gives decreasing order real exponential graph 
x= exp(t*sigma);
subplot(2,1,2);
stem(t,x);
title("Real Exponent (decreasing order)");
xlabel("time");
ylabel("x(t)");