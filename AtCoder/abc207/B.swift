private func readLn() -> String {
	return readLine()!
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readDoubles() -> [Double] {
	return readLns().compactMap{ Double($0) }
}

var arr = readDoubles()
let den = arr[2] * arr[3] - arr[1]
if den <= 0 {
	print(-1)
} else {
	let ans = arr[0] / den
	print(ans.roundedUp)
}

extension Double {
	var roundedUp: Int {
		let ans = Int(self)
		if self - Double(ans) > 0.0 {
			return ans + 1
		} else {
			return ans
		}
	}
}