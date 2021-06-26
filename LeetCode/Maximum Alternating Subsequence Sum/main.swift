class Solution {
    func maxAlternatingSum(_ nums: [Int]) -> Int {
        var ans = nums[0]
        for i in 1 ..< nums.count {
            ans += max(0, nums[i] - nums[i - 1])
        }
        return ans
    }
}