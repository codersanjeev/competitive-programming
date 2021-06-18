class Solution {
    fun maximumWealth(accounts: Array<IntArray>): Int {
        var ans = 0
        accounts.forEach { account ->
            val curr = account.sum()
            if (curr > ans) {
                ans = curr
            }
        }
        return ans
    }
}
