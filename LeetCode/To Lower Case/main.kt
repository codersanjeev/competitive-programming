class Solution {
    fun toLowerCase(s: String): String {
        var ans = ""
        for (ele in s) {
            if (ele.isUpperCase()) {
                ans += ele.toLowerCase()
            } else {
                ans += ele
            }
        }
        return ans
    }
}