class Solution {
    fun minPairSum(nums: IntArray): Int {
        nums.sort()
        var (ans, i, j) = arrayOf(0, 0, nums.size - 1)
        while (i < j) {
            ans = ans.coerceAtLeast(nums[i] + nums[j])
            ++i
            --j
        }
        return ans
    }
}