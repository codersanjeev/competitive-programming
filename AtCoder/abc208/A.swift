private func readLn() -> String {
	return readLine() ?? ""
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readInts() -> [Int] {
	return readLns().compactMap{ Int($0) }
}

var dp = [[Int]](repeating: [Int](repeating: -1, count: 1001), count: 101)

private func solve(_ a: Int, _ b: Int) -> Bool {
	if a == 0 {
		return b == 0
	}
	if dp[a][b] != -1 {
		return dp[a][b] == 1
	}
	var res = false
	for i in 1 ... 6 {
		res = res || solve(a - 1, b - i)
	}
	dp[a][b] = res ? 1 : 0
	return res
}

let ab = readInts()
if solve(ab[0], ab[1]) {
	print("Yes")
} else {
	print("No")
}