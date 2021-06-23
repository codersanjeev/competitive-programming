class Solution {
    fun numMatchingSubseq(s: String, words: Array<String>): Int {
        val index = generateSequence {
            generateSequence { s.length }.take(26).toMutableList()
        }.take(s.length + 1).toMutableList()
        for (i in s.length - 1 downTo 0) {
            for (j in 0 until 26) {
                index[i][j] = index[i + 1][j]
            }
            index[i][s[i] - 'a'] = i
        }
        var ans = 0
        for (word in words) {
            var curr = 0
            var good = true
            for (ch in word) {
                curr = index[curr][ch - 'a']
                if (curr == s.length) {
                    good = false
                    break
                }
                ++curr
            }
            if (good) ++ans
        }
        return ans
    }
}