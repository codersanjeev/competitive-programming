class Solution {
    fun superpalindromesInRange(left: String, right: String): Int {
        val (L, R) = arrayOf(left.toLong(), right.toLong())
        val all = generateAllPalindromes()
        var ans = 0
        all.forEach {
            if (it <= 1e9) {
                val x = it * it
                if (x in L..R && palindrome(x)) {
                    ans++
                }
            }
        }
        return ans
    }

    private fun generateAllPalindromes(): LongArray {
        val ans = MutableList<Long>(0) { 0 }
        for (i in 1L..9L) ans.add(i)
        for (i in 1L..10000L) {
            val s = i.toString()
            val t = s.reversed()
            ans.add((s + t).toLong())
            for (ch in '0'..'9') {
                val temp = s + ch + t
                ans.add(temp.toLong())
            }
        }
        return ans.toLongArray()
    }

    private fun palindrome(x: Long): Boolean {
        val s = x.toString()
        val t = s.reversed()
        return s == t
    }
}