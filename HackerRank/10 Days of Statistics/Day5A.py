import math
# Mean λ -> It is the average no of success that occur in the specified region.
l= float(input())
# k-> Actual no of success that occur in the specified region
k = float(input())
# Poisson Distribution
p = ((l**k)*((2.71828)**(-l)))/math.factorial(k)
print(round(p,3))
