class Solution {
    fun isSubsequence(P: String, S: String): Boolean {
        var (n, m, j) = arrayOf(P.length, S.length, 0)
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
}