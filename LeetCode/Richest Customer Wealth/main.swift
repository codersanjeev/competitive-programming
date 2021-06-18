class Solution {
    func maximumWealth(_ accounts: [[Int]]) -> Int {
        var ans = 0
        accounts.forEach { account in
            let curr = account.reduce(0, +)
            if (curr > ans) {
                ans = curr
            }
        }
        return ans
    }
}