class Solution {
    fun sortSentence(s: String): String {
        val arr = mutableListOf<Pair<Int, String>>()
        s.split(" ").forEach {
            val index = it.last() - '0'
            val word = it.substring(0, it.length - 1)
            arr.add(Pair(index, word))
        }
        arr.sortBy { it.first }
        var ans = ""
        arr.forEach {
            ans += it.second
            ans += " "
        }
        return ans.removeSuffix(" ")
    }
}