class Solution {
    fun longestOnes(nums: IntArray, k: Int): Int {
        var (lo, hi, K) = listOf(0, 0, k)
        while (hi < nums.size) {
            if (nums[hi] == 0) --K
            if (K < 0) {
                if (nums[lo] == 0) ++K
                ++lo
            }
            ++hi
        }
        return hi - lo
    }
}