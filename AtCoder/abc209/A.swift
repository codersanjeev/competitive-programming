private func readLn() -> String {
	return readLine() ?? ""
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readInts() -> [Int] {
	return readLns().compactMap{ Int($0) }
}

let ab = readInts()
var ans = ab[1] - ab[0] + 1
if ans < 0 { ans = 0 }
print(ans)