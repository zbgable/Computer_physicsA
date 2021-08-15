N_range = 1:1:1e3;
N_num = length(N_range);
for index = 1:1:N_num
    N_range(index) = 1.01^index;
end
x = rand([1,fix(max(N_range))])*2-1;
y = rand([1,fix(max(N_range))])*2-1;
sample =double(( x.^2 + y.^2 )<1);
result = zeros([1,N_num]);
for index = 1:1:N_num
    result(index) =4* mean(sample(1:(fix(N_range(index)))));
end
x_range =N_range;
Err = abs(result - pi);
scatter(log(x_range),log(Err),5,'filled','r');
hold on
p = polyfit(log(x_range),log(Err),1);
x_range_fine = min(log(x_range)):0.01:max(log(x_range));
y_fit = polyval(p,x_range_fine);
plot(x_range_fine,y_fit)% The 1/\sqrt{N} relation of the error for guessing the pi