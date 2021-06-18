class Solution {
    fun maximumUniqueSubarray(nums: IntArray): Int {
        var (curr, ans, i) = arrayOf(0, 0, 0)
        val seen = BooleanArray(nums.max()!! + 1) { false }
        for (j in nums.indices) {
            while (seen[nums[j]]) {
                seen[nums[i]] = false
                curr -= nums[i]
                ++i
            }
            seen[nums[j]] = true
            curr += nums[j]
            ans = ans.coerceAtLeast(curr)
        }
        return ans
    }
}
