class Solution {
    fun reductionOperations(nums: IntArray): Int {
        nums.sort()
        var (ans, cnt) = arrayOf(0, 0)
        for (i in 1 until nums.size) {
            if (nums[i] != nums[i - 1]) ++cnt
            ans += cnt
        }
        return ans
    }
}