def isLowerChar(c):
    return ord(c) >= 97 and ord(c) <= 122
    
def isUpperChar(c):
    return ord(c) >= 65 and ord(c) <= 90
 
def isNumber(c):
    return ord(c) >= 48 and ord(c) <= 57
 
S = input()
K = int(input())
R = "" 
 
for c in S:
    if(isLowerChar(c)):
        R += chr(((ord(c) - 97 + K) % 26) + 97)
    elif(isUpperChar(c)):
        R += chr(((ord(c) - 65 + K) % 26) + 65)
    elif(isNumber(c)):
        R += chr(((ord(c) - 48 + K) % 10) + 48)
    else:
        R += c
print(R)