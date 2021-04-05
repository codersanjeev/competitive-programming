for _ in range(int(input())) :
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    print(-sum(arr[:len(arr)-m]) + sum(arr[m:]))