class Solution {
	private var S = [Character]()
	private var P = [Character]()
	private var removable = [Int]()
	
	private func isSubsequence() -> Bool {
		var (n, m, j) = (P.count, S.count, 0)
		if n > m { return false }
		if n == m { return P == S }
		if m == 0 { return false }
		if n == 0 { return true }
		for i in 0 ..< m {
			if P[j] == S[i] {
				if j == n - 1 { return true }
				j += 1
			}
 		}
		return false
	}
	
	private func good(_ rem: Int) -> Bool {
		let temp = S
		for i in 0 ..< rem {
			S[removable[i]] = "/"
		}
		let res = isSubsequence()
		S = temp
		return res
	}
	
	func maximumRemovals(_ s: String, _ p: String, _ removable: [Int]) -> Int {
		self.removable = removable
		self.S = Array(s)
		self.P = Array(p)
		var (lo, hi, ans) = (0, removable.count, 0)
		while lo <= hi {
			let mid = lo + (hi - lo) / 2
			if good(mid) {
				ans = mid
				lo = mid + 1
			} else {
				hi = mid - 1
			}
		}
		return ans
	}
}
