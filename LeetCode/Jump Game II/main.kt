class Solution {
    fun jump(nums: IntArray): Int {
        var (ans, curr, reach) = arrayOf(0, 0, 0)
        for (i in nums.indices) {
            if (i == nums.size - 1) break
            reach = reach.coerceAtLeast(i + nums[i])
            if (i == curr) {
                ans += 1
                curr = reach
            }
        }
        return ans
    }
}