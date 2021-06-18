class Solution {
    fun maxProduct(words: Array<String>): Int {
        val arr = IntArray(words.size) { 0 }
        var (ans, one) = arrayOf(0, 1)
        for (i in words.indices) {
            for (j in words[i].indices) {
                arr[i] = arr[i].or(one.shl(words[i][j] - 'a'))
            }
        }
        for (i in words.indices) {
            for (j in i + 1 until words.size) {
                if (arr[i].and(arr[j]) == 0) {
                    ans = ans.coerceAtLeast(words[i].length * words[j].length)
                }
            }
        }
        return ans
    }
}
