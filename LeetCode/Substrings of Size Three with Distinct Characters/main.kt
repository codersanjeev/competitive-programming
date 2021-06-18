class Solution {
    fun countGoodSubstrings(s: String): Int {
        var ans = 0
        for (i in 0 until s.length - 2) {
            val temp = mutableSetOf<Char>()
            for (j in 0..2) temp.add(s[i + j])
            if (temp.size == 3) ++ans
        }
        return ans
    }
}