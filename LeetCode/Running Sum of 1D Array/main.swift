class Solution {
    func runningSum(_ arr: [Int]) -> [Int] {
        var nums = arr
        for i in 1..<nums.count {
            nums[i] += nums[i - 1]
        }
        return nums
    }
}