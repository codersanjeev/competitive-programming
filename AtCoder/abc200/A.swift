let s = readLine() ?? ""
let n = Int(s) ?? 0
if (n % 100 == 0) {
	print(n / 100)
} else {
	print((n / 100) + 1)
}
