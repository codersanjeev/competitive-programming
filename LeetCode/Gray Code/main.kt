class Solution {
    private fun grayCodeRecursive(n: Int): List<String> {
        if (n == 1) return listOf("0", "1")
        val previousCodes = grayCodeRecursive(n - 1)
        var ans = ArrayList<String>()
        for (ele in previousCodes) {
            ans.add("0" + ele)
        }
        for (ele in previousCodes.reversed()) {
            ans.add("1" + ele)
        }
        return ans
    }

    private fun toDecimal(s: String): Int {
        var (ans, one) = listOf(0, 1)
        for (i in s.indices) {
            if (s[i] == '1') {
                ans = ans.or(one.shl(i))
            }
        }
        return ans
    }

    fun grayCode(n: Int): List<Int> {
        val grayCodes = grayCodeRecursive(n)
        return grayCodes.map({ toDecimal(it) })
    }
}