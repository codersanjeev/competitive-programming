t = int(input())
for _ in range(t) :
    s = list(input())
    odd = []
    even = []
    for i in range(len(s)) :
        if(i%2 == 0) :
            even.append(s[i])
        else :
            odd.append(s[i])
    print("".join(even), end=" ")
    print("".join(odd))