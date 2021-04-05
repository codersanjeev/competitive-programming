class Solution {
    fun decompressRLElist(nums: IntArray): IntArray {
        val n = nums.count()
        var ans = IntArray(0)
        for (i in 0..n-2 step 2) {
            var curr = IntArray(nums[i]) { nums[i + 1] }
            ans += curr
        }
        return ans
    }
}