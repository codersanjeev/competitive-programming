private func readLn() -> String {
	return readLine() ?? ""
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readInts() -> [Int] {
	return readLns().compactMap{ Int($0) }
}

let NAXY = readInts()
if NAXY[0] <= NAXY[1] {
	print(NAXY[0] * NAXY[2])
} else {
	print(NAXY[1] * NAXY[2] + (NAXY[0] - NAXY[1]) * NAXY[3])
}