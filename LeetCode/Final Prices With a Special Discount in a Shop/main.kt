class Solution {
    fun finalPrices(prices: IntArray): IntArray {
        val n = prices.count()
        for (i in 0 until n) {
            for (j in i + 1 until n) {
                if (prices[j] <= prices[i]) {
                    prices[i] -= prices[j]
                    break
                }
            }
        }
        return prices
    }
}