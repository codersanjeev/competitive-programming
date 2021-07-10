private func readLn() -> String {
	return readLine() ?? ""
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readInts() -> [Int] {
	return readLns().compactMap{ Int($0) }
}

let nx = readInts()
let a = readInts()
var y = 0
for i in a.indices {
	y += a[i]
	if i % 2 == 1 {
		y -= 1
	}
}
if y <= nx[1] {
	print("Yes")
} else {
    print("No")
}