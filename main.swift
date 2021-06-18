private func readLn() -> String {
	return readLine()!
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readInt() -> Int {
	return Int(readLn()) ?? 0
}

private func readInts() -> [Int] {
	return readLns().compactMap{ Int($0) }
}

private func readLong() -> Int64 {
	return Int64(readLn()) ?? Int64(0)
}

private func readLongs() -> [Int64] {
	return readLns().compactMap{ Int64($0) }
}

private func readDouble() -> Double {
	return Double(readLn()) ?? Double(0)
}

private func readDoubles() -> [Double] {
	return readLns().compactMap{ Double($0) }
}