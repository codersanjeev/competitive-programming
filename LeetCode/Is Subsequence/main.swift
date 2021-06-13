class Solution {
    func isSubsequence(_ s: String, _ p: String) -> Bool {
        let P = Array<Character>(s)
        let S = Array<Character>(p)
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
}