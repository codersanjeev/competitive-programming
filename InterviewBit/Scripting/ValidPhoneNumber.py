import re

def validateNumber(text) :
    m1 = re.search(r"[(]{1}[0-9]{3}[)]{1}\s[0-9]{3}-[0-9]{4}", text)
    m2 = re.search(r"[0-9]{3}-[0-9]{3}-[0-9]{4}", text)
    if m1 and len(text) is 14 :
        return True
    if m2 and len(text) is 12 :
        return True
    return False

while True :
    try :
        text = input()
        if(validateNumber(text)) :
            print(text)
    except EOFError :
        break
