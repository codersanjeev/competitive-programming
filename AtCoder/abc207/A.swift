private func readLn() -> String {
	return readLine()!
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readInts() -> [Int] {
	return readLns().compactMap{ Int($0) }
}

var arr = readInts()
arr.sort()
print(arr[1] + arr[2])