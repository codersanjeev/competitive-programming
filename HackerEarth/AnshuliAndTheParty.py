import math
T=int(input())
while T:
    a,b=list(map(int,input().split()))
    print (pow(a,b,1000000007))
    T-=1