private func readLn() -> String {
	return readLine() ?? " "
}

private func readLong() -> Int64 {
	return Int64(readLn()) ?? Int64(0)
}

let n = readLong()
var (lo, hi, ans) = (Int64(0), Int64(1e5), Int64(1e5))
while lo <= hi {
	let mid = lo + (hi - lo) / 2
	if (mid * mid) + mid >= 2 * n {
		ans = mid
		hi = mid - 1
	} else {
		lo = mid + 1
	}
}
print(ans)