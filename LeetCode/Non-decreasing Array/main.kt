class Solution {
    fun checkPossibility(nums: IntArray): Boolean {
        var changed = false
        var index = 1
        while (index < nums.size) {
            if (nums[index] < nums[index - 1]) {
                if (changed) return false
                changed = true
                if (index - 2 < 0 || nums[index - 2] <= nums[index]) {
                    nums[index - 1] = nums[index]
                } else {
                    nums[index] = nums[index - 1]
                }
            }
            ++index
        }
        return true
    }
}