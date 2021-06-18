import sys 
import math

b = [float(i) for i in sys.stdin.readline().split()]

def nCr(n,r):
    f = math.factorial
    return f(n)/( f(r) * f(n-r))

pb = b[0]/(b[0]+b[1])
pg = 1-pb

n = 6
p3b = 0 

for i in range(3,n+1):
    p3b += nCr(n,i) * (pb**i) * (pg**(n-i))

print(round(p3b,3))
