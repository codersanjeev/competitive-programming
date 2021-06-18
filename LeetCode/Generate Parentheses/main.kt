class Solution {
    private var ans = ArrayList<String>()
    
    private tailrec fun generateParenthesisRecursive(n: Int, l: Int, r: Int, s: String) {
        if (l == n && r == n) {
            ans.add(s)
            return
        }
        if (l < n) {
            generateParenthesisRecursive(n, l + 1, r, "$s(")
        }
        if (r < l) {
            generateParenthesisRecursive(n, l, r + 1, "$s)")    
        }
    }

    fun generateParenthesis(n: Int): List<String> {
        generateParenthesisRecursive(n, 0, 0, "")        
        return ans
    }
}