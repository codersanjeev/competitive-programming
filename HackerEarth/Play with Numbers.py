def main() :
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))
    sumarr = []
    s = 0
    for i in arr :
        s += i
        sumarr.append(s)
    for _ in range(q) :
        l, r = map(int, input().split())
        if(l-1 == 0) :
            s = sumarr[r-1]
        else :
            s = sumarr[r-1] - sumarr[l-2]
        ans = int(s / (r-l+1))
        print(ans)

if __name__ == "__main__" :
    main()