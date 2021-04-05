class Solution {
    fun arrayPairSum(nums: IntArray): Int {
        nums.sort()
        var ans = 0
        for (i in 0 until nums.count()) {
            if (i % 2 == 0) {
                ans += nums[i]
            }
        }
        return ans
    }
}