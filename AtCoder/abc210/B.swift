private func readLn() -> String {
	return readLine() ?? ""
}

private func readInt() -> Int {
	return Int(readLn()) ?? 0
}

let N = readInt()
let S = readLn()
var (first, index) = (true, 0)
for ch in S {
	if ch == Character("1") {
		first = index % 2 == 0
		break
	}
	index += 1
}
if first {
	print("Takahashi")
} else {
	print("Aoki")
}