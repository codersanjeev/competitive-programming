n, k = map(int, input().split())
arr = list(map(int, input().split()))
for i in range(n-k+1) :
    print(max(arr[i:i+k]), end=" ")