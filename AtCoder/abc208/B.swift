private func readLn() -> String {
	return readLine() ?? ""
}

private func readInt() -> Int {
	return Int(readLn()) ?? 0
}

var n = readInt()
var coins = [Int]()
var (coin, ans) = (1, 0)
for i in 1 ... 10 {
	coin *= i
	for _ in 1 ... 100 {
		coins.append(coin)
	}
}
for ele in coins.reversed() {
	if ele <= n {
		n -= ele
		ans += 1
	}
}
print(ans)