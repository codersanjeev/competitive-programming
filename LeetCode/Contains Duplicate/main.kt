class Solution {
    fun containsDuplicate(nums: IntArray): Boolean {
        nums.sort()
        val n = nums.count()
        for (i in 0 until n - 1) {
            if (nums[i] == nums[i + 1]) {
                return true
            }
        }
        return false
    }
}
