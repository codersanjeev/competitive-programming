n=(int)(input())
while(n>0):
    n-=1
    s=input()
    sum1=0
    for i in s:
        if(i>='0' and i<='9'):
            sum1+=int(i)
    print(sum1)