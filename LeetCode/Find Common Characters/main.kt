class Solution {
    fun commonChars(A: Array<String>): List<String> {
        var freq = IntArray(26) { Integer.MAX_VALUE }
        A.forEach { s ->
            var cnt = IntArray(26) { 0 }
            s.forEach { ch ->
                cnt[ch - 'a']++
            }
            for (i in 0 until 26) {
                freq[i] = Math.min(freq[i], cnt[i]);
            }
        }
        var arr = mutableListOf<String>()
        for (i in 0 until 26) {
            var cnt = freq[i]
            while (cnt > 0) {
                val curr = ('a' + i)
                arr.add(curr + "")
                cnt--
            }
        }
        return arr
    }
}