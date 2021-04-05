n = int(input())
arr = list(map(int, input().split()))
chk = 2*(n-1)
if(sum(arr) == chk) :
    print("Yes")
else :
    print("No")