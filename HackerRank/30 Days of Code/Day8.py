n = int(input())
database = {}
for _ in range(n) :
    name, phone = input().split()
    phone = int(phone)
    database[name] = phone
    
while(True) :
    s = input()
    if(s in database.keys()) :
        ans = str(database[s])
        print(s+"="+ans)
    else :
        print("Not found")
