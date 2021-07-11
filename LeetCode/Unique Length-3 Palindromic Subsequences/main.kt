class Solution {
    fun countPalindromicSubsequence(s: String): Int {
        val index = Array(26) { arrayOf(-1, -1) }
        for (i in s.indices) {
            val curr = s[i] - 'a'
            if (index[curr][0] == -1)
                index[curr][0] = i
            else
                index[curr][1] = i
        }
        var ans = 0
        for (i in 0 until 26) {
            val curr = HashSet<Char>()
            for (j in index[i][0] + 1 until index[i][1]) {
                curr.add(s[j])
            }
            ans += curr.size
        }
        return ans
    }
}