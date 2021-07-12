class Solution {
    fun isIsomorphic(s: String, t: String): Boolean {
        val a = IntArray(256)
        val b = IntArray(256)
        for (i in s.indices) {
            val (x, y) = listOf(s[i].toInt(), t[i].toInt())
            if (a[x] != b[y]) return false
            a[x] = i + 1
            b[y] = i + 1
        }
        return true
    }
}