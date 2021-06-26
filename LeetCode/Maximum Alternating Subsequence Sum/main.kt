import java.lang.Integer.max

class Solution {
    fun maxAlternatingSum(nums: IntArray): Long {
        var ans = nums[0].toLong()
        for (i in 1 until nums.size) {
            ans += max(0, nums[i] - nums[i - 1])
        }
        return ans
    }
}