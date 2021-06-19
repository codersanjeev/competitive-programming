private func readLn() -> String {
	return readLine() ?? " "
}

private func readDouble() -> Double {
	return Double(readLn()) ?? Double(0)
}

let n = readDouble()
var ans = "so-so"
let m = Int(n * 1.08)
if m < 206 {
	ans = "Yay!"
} else if m > 206 {
	ans = ":("
}
print(ans)
