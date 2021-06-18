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

let n = readInts()
let arr = readInts()
let sum = arr.reduce(0, +)
var dp = [Bool](repeating: false, count: sum + 1)
dp[0] = true
for i in arr.indices {
	for rem in stride(from: sum - arr[i], to: -1, by: -1) {
		if dp[rem] {
			dp[rem + arr[i]] = true
		}
	}
}
var ans = sum
for i in dp.indices {
	if (dp[i]) {
		ans = min(ans, max(i, sum - i))
	}
}
print(ans)
