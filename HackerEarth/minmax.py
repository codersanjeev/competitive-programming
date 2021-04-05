n = int(input())
arr = list(map(int, input().split()))
print(sum(arr)-max(arr), end=" ")
print(sum(arr)-min(arr))