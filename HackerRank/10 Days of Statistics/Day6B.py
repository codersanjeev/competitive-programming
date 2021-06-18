import math
x = 250
n = 100
sampling_mean = 2.4
sampling_stdev = 2.0
stdev = sampling_stdev * math.sqrt(n)

cdf = 0.5 * (1 + math.erf((x - sampling_mean * n) / (stdev * math.sqrt(2))))

print(round(cdf,4))