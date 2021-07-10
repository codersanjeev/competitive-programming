private func readLn() -> String {
	return readLine() ?? ""
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readInt() -> Int {
	return Int(readLn()) ?? 0
}

private func readLongs() -> [Int64] {
	return readLns().compactMap{ Int64($0) }
}

let mod = Int64(1e9 + 7)
let n = readInt()
var arr = readLongs()
arr.sort()
var ans = Int64(1)
for i in arr.indices {
	ans = ans * max(0, arr[i] - Int64(i)) % mod
}
print(ans)