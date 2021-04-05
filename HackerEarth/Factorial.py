def factorial(n) :
    if(n is 0 or n is 1) :
        return 1
    else :
        return factorial(n-1)*n

for _ in range(int(input())) :
    n = int(input())
    print(factorial(n))