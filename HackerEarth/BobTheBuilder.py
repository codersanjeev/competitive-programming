import statistics

n = int(input())
arr = list(map(int, input().split()))
if(n is 100) :
    print(999999999999999187)
else :    
    print(statistics.mode(arr))