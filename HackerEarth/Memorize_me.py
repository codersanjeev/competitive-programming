import collections

n = int(input())
arr = list(map(int, input().split()))
freq = collections.Counter(arr)
q = int(input())
for _ in range(q) :
    x = int(input())
    if(x in freq.keys()) :
        print(freq[x])
    else :
        print("NOT PRESENT")
    