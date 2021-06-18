def showTest(n, k, a):
    print str(n) + " " + str(k)
    print " ".join(map(str, a))

testCases = 5
print testCases
showTest(4, 3, [-1, 0, 4, 2])
showTest(5, 2, [0, -1, 2, 1, 4])
showTest(7, 6, [2, 0, -1, 1, 1, 1, 1])
showTest(3, 1, [-1, 0, 4])
showTest(6, 4, [0, -1, 1, 4, 5, 6])