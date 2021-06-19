private func readLn() -> String {
	return readLine() ?? " "
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

let n = readInt()
let arr = readInts()
var mp = [Int : Int]()
var ans = Int64(0)
for (i, ele) in arr.enumerated() {
	ans += Int64(i - (mp[ele] ?? 0))
	mp[ele] = (mp[ele] ?? 0) + 1
}
print(ans)