class Solution {
    func maxProduct(_ nums: [Int]) -> Int {
        var ans = nums.sorted()
        let n = ans.count
        return (ans[n - 1] - 1) * (ans[n - 2] - 1)
    }
}