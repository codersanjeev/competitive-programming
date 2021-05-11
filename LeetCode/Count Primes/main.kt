class Solution {
    fun countPrimes(n: Int): Int {
        if (n == 0 || n == 1) return 0
        val prime = IntArray(n) { 1 }
        prime[0] = 0
        prime[1] = 0
        var ans = 0
        for (i in 2 until n) {
            if (prime[i] == 1) {
                var j = 2 * i
                while (j < n) {
                    prime[j] = 0
                    j += i
                }
            }
        }
        prime.forEach {
            if (it == 1) {
                ans++
            }
        }
        return ans
    }
}
