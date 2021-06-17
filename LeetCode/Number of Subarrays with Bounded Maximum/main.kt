class Solution {

    private fun solve(nums: IntArray, maxValue: Int): Int {
        var (ans, curr) = arrayOf(0, 0)
        for (ele in nums) {
            curr = if (ele <= maxValue) curr + 1 else 0
            ans += curr
        }
        return ans
    }

    fun numSubarrayBoundedMax(nums: IntArray, left: Int, right: Int): Int {
        return solve(nums, right) - solve(nums, left - 1)
    }
}