s = input()
count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
for i in s :
    if(i == '0') :
        count[0]+=1
    elif(i == '1') :
        count[1]+=1
    elif(i == '2') :
        count[2]+=1
    elif(i == '3') :
        count[3]+=1
    elif(i == '4') :
        count[4]+=1
    elif(i == '5') :
        count[5]+=1
    elif(i == '6') :
        count[6]+=1
    elif(i == '7') :
        count[7]+=1
    elif(i == '8') :
        count[8]+=1
    else :
        count[9]+=1
for i in range(10) :
    ele = str(count[i])
    j = str(i)
    print(j+" "+ele)