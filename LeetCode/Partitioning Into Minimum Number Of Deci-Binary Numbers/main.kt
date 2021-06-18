class Solution {
    fun minPartitions(s: String): Int {
        var ans = 0
        s.forEach {
            ans = ans.coerceAtLeast(it - '0')
        }
        return ans
    }
}