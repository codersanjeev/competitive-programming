l, r = map(int, input().split())
arr = []
while True :
    try :
        text = input()
        arr.append(text)
    except EOFError :
        break
for i in range(l - 1, r) :
    print(arr[i - 1])
