def countSteps(n) :
    if(n < 0) :
        return 0
    elif(n is 0) :
        return 1
    elif(n is 1) :
        return 1
    elif(n is 2) :
        return 2
    
    else :
        steps = [0 for i in range(n+1)]
        steps[0] = 1
        steps[1] = 1
        steps[2] = 2
        for i in range(3, n+1) :
            steps[i] = steps[i-1] + steps[i-2] + steps[i-3]
        return steps[n]


s = int(input().strip())
for a0 in range(s):
    n = int(input().strip())
    print(countSteps(n))
