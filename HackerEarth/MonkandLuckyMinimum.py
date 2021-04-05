for _ in range(int(input())) :
    n = int(input())
    arr = list(map(int, input().split()))
    x = min(arr)
    
    if(arr.count(x)%2 is 0) :
        print("Unlucky")
    
    else :
        print("Lucky")