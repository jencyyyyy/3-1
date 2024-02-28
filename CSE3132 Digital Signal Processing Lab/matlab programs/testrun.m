n1=-10:10;
x=(n1>=0);
n2=n1+3;
y=x;
u=min(min(n1),min(n2));
t=max(max(n1),max(n2));
r=u:1:t;
z1=[];
temp=1;
for i=1:length(r)
    if(r(i)<min(n1) || r(i)>max(n1))
      z1=[z1 0];
    else
        z1=[z1 x(temp)];
        temp=temp+1;
    end
end
z2=[];
temp=1;
for i=1:length(r)
    if(r(i)<min(n2) || r(i)>max(n2))
      z2=[z2 0];
    else
        z2=[z2 y(temp)];
        temp=temp+1;
    end
end
z=z1-z2;
subplot(3,1,1);
stem(r,z1);
xlabel('Time sample');
ylabel('Amplitude');
title('First signal');
subplot(3,1,2);
stem(r,z2);
xlabel('Time sample');
ylabel('Amplitude');
title('Second signal');
subplot(3,1,3);
stem(r,z);
xlabel('Time sample');
ylabel('Amplitude');
title('Signal after Subtraction');