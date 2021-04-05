class Solution {
    func finalPrices(_ A: [Int]) -> [Int] {
        var prices = A
        let n = prices.count
        for i in 0..<n {
            for j in i+1..<n {
                if (prices[j] <= prices[i]) {
                    prices[i] -= prices[j]
                    break
                }
            }
        }
        return prices
    }
}