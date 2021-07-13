class Solution {
    fun findPeakElement(nums: IntArray): Int {
        var (lo, hi, ans) = listOf(0, nums.size - 1, nums.size - 1)
        while (lo <= hi) {
            val mid = lo + (hi - lo) / 2
            if (mid + 1 < nums.size && nums[mid] > nums[mid + 1]) {
                ans = mid
                hi = mid - 1
            } else {
                lo = mid + 1
            }
        }
        return ans
    }
}