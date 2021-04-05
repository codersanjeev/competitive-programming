n = input()
n = int(n)
arr = list(map(int, input().split()))
arr.sort()
if(arr[n-1] < 0) :
    # 0 0
    print("{} {}".format(arr[n-1], 1))
elif(arr[n-1] is 0) :
    count = 0
    for i in range(n-1, -1, -1) :
        if(arr[i] is 0) :
            count = count + 1
    # 0 count
    print("0 {}".format(count))
else :
    count = 0
    max_sum = 0
    for i in range(n-1, -1, -1) :
        if(arr[i] >= 0) :
            max_sum = max_sum + arr[i]
            count = count + 1
    # 0 0
    print("{} {}".format(max_sum, count))