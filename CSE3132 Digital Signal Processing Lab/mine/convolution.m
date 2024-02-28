clc
clear all
close all
x=input('Enter the first array');
h=input('Enter the second array');
z=[];
for i=1:length(x)
    g=h.*x(i);
    z=[z;g];
end
[r ,c]=size(z);
k=r+c;
t=2;
y=[];
cd=0;
while(t<=k)
    for i=1:r
        for j=1:c
            if((i+j)==t)
               cd=cd+z(i,j);
            end
        end
    end
    t=t+1;
    y=[y cd];
    cd=0;
end
disp(y);