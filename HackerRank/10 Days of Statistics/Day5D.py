import math
mean, std = 70, 10
cdf = lambda x: 0.5 * (1 + math.erf((x - mean) / (std * (2 ** 0.5))))
print(round((1-cdf(80))*100,2))
print(round((1-cdf(60))*100,2))
print(round((cdf(60))*100,2))