class Solution {
    fun removeOccurrences(s: String, part: String): String {
        var ans = s
        while (ans.contains(part)) {
            ans = ans.replaceFirst(part, "")
        }
        return ans
    }
}