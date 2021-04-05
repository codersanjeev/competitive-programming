def f(num) -> str:
    roman = ''
    while num > 0:
        if num >= 1000:
            roman = roman + 'M'
            num -= 1000
        elif num >= 900:
            roman += "CM"
            num -= 900
        elif num >= 500:
            roman += 'D'
            num -= 500
        elif num >= 400:
            roman += 'CD'
            num -= 400
        elif num >= 100:
            roman += 'C'
            num -= 100
        elif num >= 90:
            roman += 'XC'
            num -= 90
        elif num >= 50:
            roman += 'L'
            num -= 50
        elif num >= 40:
            roman += 'XL'
            num -= 40
        elif num >= 10:
            roman += 'X'
            num -= 10
        elif num == 9:
            roman += 'IX'
            num -= 9
        elif num >= 5:
            roman += 'V'
            num -= 5
        elif num == 4:
            roman += 'IV'
            num -= 4
        else:
            roman += 'I'
            num -= 1
    return roman

while True :
    try :
        n = int(input())
        print(f(n))
    except EOFError :
        break
