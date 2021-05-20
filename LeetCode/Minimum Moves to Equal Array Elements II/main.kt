class Solution {
    fun minMoves2(nums: IntArray): Int {
        nums.sort()
        var (ans, median) = arrayOf(0, nums[nums.size / 2])
        nums.forEach {
            ans += Math.abs(it - median)
        }
        return ans
    }
}
