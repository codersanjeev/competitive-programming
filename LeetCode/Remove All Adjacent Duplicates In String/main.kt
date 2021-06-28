class Solution {
    fun removeDuplicates(s: String): String {
        val st = Stack<Char>()
        var good: Boolean
        for (ch in s) {
            good = false
            while (st.isNotEmpty() && st.peek() == ch) {
                good = true
                st.pop()
            }
            if (good) continue
            st.push(ch)
        }
        var ans = ""
        while (st.isNotEmpty()) ans += st.pop()
        return ans.reversed()
    }
}