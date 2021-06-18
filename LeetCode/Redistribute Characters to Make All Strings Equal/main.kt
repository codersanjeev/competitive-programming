class Solution {
    fun makeEqual(words: Array<String>): Boolean {
        val freq = IntArray(26)
        for (word in words) {
            for (ch in word) {
                freq[ch - 'a']++
            }
        }
        for (ele in freq) {
            if (ele % words.size != 0) {
                return false
            }
        }
        return true
    }
}