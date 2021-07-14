class Solution {
    fun customSortString(order: String, str: String): String {
        val orderMap = hashMapOf<Char, Int>()
        for (i in order.indices) {
            orderMap[order[i]] = i + 1
        }
        return str.toCharArray().sortedBy {
            orderMap[it]
        }.joinToString("")
    }
}