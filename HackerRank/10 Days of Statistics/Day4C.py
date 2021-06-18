num, den = map(int, input().split())
n = int(input())
s = num/den
f = 1-s
ans = (s*pow(f, n-1))
print(round(ans, 3))
