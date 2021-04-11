class Solution {
    fun findTheWinner(n: Int, k: Int): Int {
        var ans = 0
        for (i in 2..n) {
            ans = (ans + k) % i
        }
        return ans + 1
    }
}