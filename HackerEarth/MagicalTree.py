n = int(input())
answer = 0
for _ in range(n) :
    exp = input()
    answer = max(answer, eval(exp))
print(answer)