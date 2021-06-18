n = int(input())
x = list(map(int, input().split()))
w = list(map(int, input().split()))
s = 0
s1 = 0
for i in range(n) :
    s += x[i]*w[i]
    s1 += w[i]
print("%.1f"%(s/s1))