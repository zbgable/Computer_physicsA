clc,clear,close all; %清空、关闭所有
%%load data
data1 = load("error--N_samp.txt");
data2 = load("error--gamma-200.txt");

N_samp=data1(:,1);
error_N=data1(:,3);
acce_N=data1(:,4);

gamma =data2(:,1);
error_g=data2(:,3);
acce_g=data2(:,4);
%%plot
subplot(2,2,1);
fig=polyfit(log(N_samp),log(error_N),1);
plot(log(N_samp),log(error_N),'b--*');
title('log(Nsamp)-log(error)');
xlabel('log(Nsamp)');
ylabel('error');

subplot(2,2,2);
plot(log(N_samp),acce_N,'black--*');
title('log(Nsamp)-acce');
xlabel('log(Nsamp)');
ylabel('acce');

subplot(2,2,3);
plot(gamma,error_g,'r--*');
title('gamma-error');
xlabel('gamma');
ylabel('error');

subplot(2,2,4);
plot(gamma,acce_g,'g--*');
title('gamma-acce');
xlabel('gamma');
ylabel('acce');


