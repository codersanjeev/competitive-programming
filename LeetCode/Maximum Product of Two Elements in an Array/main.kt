class Solution {
    fun maxProduct(nums: IntArray): Int {
        nums.sort()
        val n = nums.count()
        return (nums[n - 1] - 1) * (nums[n - 2] - 1)
    }
}