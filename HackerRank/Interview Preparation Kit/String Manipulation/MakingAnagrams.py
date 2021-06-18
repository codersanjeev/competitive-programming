def number_needed(a, b):
    s = "abcdefghijklmnopqrstuvwxyz"
    s = list(s)
    countA = [0 for i in range(26)]
    countB = [0 for i in range(26)]
    for i in range(len(s)) :
        for j in range(len(a)) :
            if(a[j] is s[i]) :
                countA[i]+=1
            
        for j in range(len(b)) :
            if(b[j] is s[i]) :
                countB[i]+=1
    ans = 0
    for i in range(26) :
        if(countA[i] != countB[i]) :
            ans += abs(countB[i]-countA[i])
    return ans


a = input()
b = input()
print(number_needed(a, b))
