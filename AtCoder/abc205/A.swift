let ab = readLine()!.split(separator: " ")
var ans = Double(ab[0]) ?? Double(0)
ans *= Double(ab[1]) ?? Double(0)
ans /= 100
print(ans)