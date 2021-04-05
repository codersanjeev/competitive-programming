n, q = map(int, input().split())
arr = list(map(int, input().split()))
for _ in range(q) :
    x, y, z = map(int, input().split())
    if(x is 1) :
        arr[y] = z
    else :
        print(sum(arr[y:z+1]))