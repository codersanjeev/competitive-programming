mod = 1000000007
n = int(input())
arr = list(map(int, input().split()))
temp = arr[:]
for i in range(n - 2, -1, -1) :
	temp[i] += temp[i + 1]
ans = 0
for i in range(n - 1) :
	ans = (ans + (arr[i] * temp[i + 1]) % mod) % mod
print(ans % mod)