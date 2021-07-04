class Solution {
    func buildArray(_ nums: [Int]) -> [Int] {
        var ans = [Int](repeating: 0, count: nums.count)
        for i in nums.indices {
            ans[i] = nums[nums[i]]
        }
        return ans
    }
}