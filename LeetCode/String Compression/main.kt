class Solution {
    fun compress(chars: CharArray): Int {
        val len = chars.size
        val ans = StringBuilder()
        ans.append(chars[0])
        var curr = 1
        for (i in 1 until len) {
            if (ans.last().equals(chars[i])) {
                curr++
            } else {
                if (curr > 1) {
                    ans.append(curr)
                }
                ans.append(chars[i])
                curr = 1
            }
        }
        if (curr > 1) {
            ans.append(curr)
        }
        val m = ans.count()
        if (m <= len) {
            for (i in 0 until m) {
                chars[i] = ans[i]
            }
        }
        return m
    }
}
