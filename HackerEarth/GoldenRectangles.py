ans = 0
for _ in range(int(input())) :
    w, h = map(int, input().split())
    if((max(w, h)/min(w, h) >= 1.6) and (max(w, h)/min(w, h) <= 1.7)) :
        ans += 1
print(ans)