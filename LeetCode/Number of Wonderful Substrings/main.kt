class Solution {
    fun wonderfulSubstrings(word: String): Long {
        var ans = 0L
        var (x, one) = listOf(0, 1)
        val mp = hashMapOf<Int, Int>()
        mp[0] = 1
        for (j in word.indices) {
            x = x.xor(one.shl(word[j] - 'a'))
            ans += mp.getOrDefault(x, 0)
            for (i in 0 until 10) {
                ans += mp.getOrDefault(x.xor(one.shl(i)), 0)
            }
            mp[x] = mp.getOrDefault(x, 0) + 1
        }
        return ans
    }
}