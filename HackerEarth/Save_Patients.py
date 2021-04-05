n = int(input())
strengthVaccines = list(map(int, input().split()))
midichlorianCount = list(map(int, input().split()))
strengthVaccines.sort()
midichlorianCount.sort()
flag = False
for i in range(n) :
    if(strengthVaccines[i] <= midichlorianCount[i]) :
        flag = True
        break
if(flag) :
    print("No")
else :
    print("Yes")