class Solution {
    private fun binarySearch(nums: IntArray, i: Int, target: Int): Int {
        var (lo, hi, ans) = listOf(i, nums.size - 1, 0)
        while (lo <= hi) {
            val mid = lo + (hi - lo) / 2
            if (nums[mid] < target) {
                ans = mid + 1 - i
                lo = mid + 1
            } else {
                hi = mid - 1
            }
        }
        return ans
    }

    fun triangleNumber(nums: IntArray): Int {
        nums.sort()
        var ans = 0
        for (i in nums.indices) {
            for (j in i + 1 until nums.size) {
                ans += binarySearch(nums, j + 1, nums[i] + nums[j])
            }
        }
        return ans
    }
}