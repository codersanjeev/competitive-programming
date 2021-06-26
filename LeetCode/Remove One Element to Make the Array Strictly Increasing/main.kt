class Solution {
    fun canBeIncreasing(nums: IntArray): Boolean {
        for (i in nums.indices) {
            var prev = -1
            var found = true
            for (j in nums.indices) {
                if (i != j) {
                    if (nums[j] > prev) prev = nums[j]
                    else found = false
                }
            }
            if (found) return true
        }
        return false
    }
}