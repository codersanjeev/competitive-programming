class Solution {
    fun subsetXORSum(nums: IntArray): Int {
        var (ans, n, one) = arrayOf(0, nums.size, 1)
        for (mask in 1 until one.shl(n)) {
            var curr = 0
            for (i in 0 until n) {
                if (mask.and(one.shl(i)) != 0) curr = curr.xor(nums[i])
            }
            ans += curr
        }
        return ans
    }
}