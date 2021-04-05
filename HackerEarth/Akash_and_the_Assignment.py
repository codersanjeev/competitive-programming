n, q = map(int, input().split())
s = list(input())
for _ in range(q) :
    l, r, k = map(int, input().split())
    sub = s[l-1:r]
    sub.sort()
    print(sub[k-1])