private func readLn() -> String {
	return readLine() ?? ""
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readLongs() -> [Int64] {
	return readLns().compactMap{ Int64($0) }
}

var nk = readLongs()
var id = readLongs()
var ans = [Int64](repeating: nk[1] / nk[0], count: Int(nk[0]))
nk[1] %= nk[0]
var idMap = [Int64 : Int64]()
for i in id.indices {
	idMap[id[i]] = Int64(i)
}
for ele in id.sorted() {
	if nk[1] == 0 { break }
	let index = idMap[ele] ?? Int64(0)
	ans[Int(index)] += 1
	nk[1] -= 1
}
for ele in ans {
	print(ele)
}