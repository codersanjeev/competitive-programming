n= int(input())
num= list(map(int, input().split(' ')))
single_num= 0
for i in range(n):
    single_num += num[i]*(10**i)
if int(single_num)%11 ==0:
    print("YES")
else:
    print('NO')