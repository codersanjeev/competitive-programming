for _ in range(int(input())) :
    n = int(input())
    x = 2 ** n
    x = str(x)
    ans = 0
    for i in x :
        ans = ans + int(i)
    print(ans)