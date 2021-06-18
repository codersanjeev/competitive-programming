class Solution {
    private var S = CharArray(0)
    private var P = CharArray(0)
    private var removable = IntArray(0)

    private fun isSubsequence(): Boolean {
        var (n, m, j) = arrayOf(P.size, S.size, 0)
        if (n > m) return false
        if (n == m) return P.contentEquals(S)
        if (m == 0) return false
        if (n == 0) return true
        for (i in 0 until m) {
            if (P[j] == S[i]) {
                if (j == n - 1) return true
                ++j
            }
        }
        return false
    }

    private fun good(rem: Int): Boolean {
        val temp = S.copyOf()
        for (i in 0 until rem) S[removable[i]] = '/'
        val res = isSubsequence()
        S = temp.copyOf()
        return res
    }

    fun maximumRemovals(s: String, p: String, removable: IntArray): Int {
        this.removable = removable
        this.S = s.toCharArray()
        this.P = p.toCharArray()
        var (lo, hi, ans) = arrayOf(0, removable.size, 0)
        while (lo <= hi) {
            val mid = lo + (hi - lo) / 2
            if (good(mid)) {
                ans = mid
                lo = mid + 1
            } else {
                hi = mid - 1
            }
        }
        return ans
    }
}