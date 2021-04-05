import sys

limit = 2000001
suml = [0] * limit
a = [True] * limit
a[0] = a[1] = False
for i, isprime in enumerate(a):
    if isprime:
        suml[i] = suml[i-1] + i
        for n in range(i*i, limit, i):
            a[n] = False
    else:
        suml[i] = suml[i-1]

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(suml[n])
