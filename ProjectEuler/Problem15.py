from math import factorial as f

for _ in range(int(input())) :
    n, m = map(int, input().split())
    print(f(n+m)//(f(n)*f(m))%1000000007)
