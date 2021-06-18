let s = readLine() ?? ""
let nk = s.split(separator: " ").map({ Int64($0) ?? Int64(0) })
var (n, k) = (nk[0], nk[1])

while (k > 0) {
	if (n % 200 == 0) {
		n /= 200
	} else {
		let s = String(n) + "200"
		n = Int64(s) ?? Int64(0)
	}
	k -= 1
}

print(n)
