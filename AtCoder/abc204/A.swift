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

let xy = readInts()
if xy[0] == xy[1] {
	print(xy[0])
} else {
	print(3 - xy.reduce(0, +))
}
