t = int(input())
for _ in range(t) :
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    if(k > arr[0]) :
        print(abs(k-arr[0]))
    else :
        print(0)