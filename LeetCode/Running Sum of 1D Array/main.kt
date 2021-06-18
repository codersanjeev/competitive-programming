class Solution {
    fun runningSum(nums: IntArray): IntArray {
        for (i in 1 until nums.count()) {
            nums[i] += nums[i - 1]
        }
        return nums
    }
}