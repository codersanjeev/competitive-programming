import math

def checkPrime(n) :
    if(n is 1) :
        return False
    elif(n is 2 or n is 3) :
        return True
    elif (n%2 is 0 or n%3 is 0) :
        return False
    else:
        for i in range(3, int(int(pow(n, 0.5))+1), 2) :
            if (n%i is 0) :
                return False
    return True
    
p = int(input().strip())
for a0 in range(p):
    n = int(input().strip())
    if(checkPrime(n) is True) :
        print("Prime")
    else :
        print("Not prime")
