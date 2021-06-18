extension String {
	var intValue: Int {
		return Int(self) ?? 0
	}
}

private func readLn() -> String { return readLine() ?? "" }
private func readLns() -> [String] {
	return readLn().split(separator: " ").compactMap({ String($0) })
}
private func readInt() -> Int {
	return readLn().intValue
}
private func readInts() -> [Int] {
	return readLns().map({ $0.intValue })
}

let n = readInt()
let arr = readInts()
var ans = 0
for ele in arr {
	ans += max(0, ele - 10)
}
print(ans)
