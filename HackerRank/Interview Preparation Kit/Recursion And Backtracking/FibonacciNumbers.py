def fibonacci(n):
    if(n is 0 or n is 1) :
        return n
    else :
        return fibonacci(n-1)+fibonacci(n-2)
n = int(input())
print(fibonacci(n))
