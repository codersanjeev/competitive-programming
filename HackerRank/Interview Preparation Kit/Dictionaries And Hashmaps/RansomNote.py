from collections import Counter

def ransom_note(magazine, ransom):
    return not (Counter(ransom) - Counter(magazine))

m, n = map(int, input().strip().split(' '))
magazine = input().strip().split(' ')
ransom = input().strip().split(' ')
answer = ransom_note(magazine, ransom)

if(answer):
    print("Yes")
else:
    print("No")

