var nums = readLine()!.split(separator: " ").map({ Int($0)! })
print(21 - nums.reduce(0, +))
