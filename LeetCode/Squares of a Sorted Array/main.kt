class Solution {
    fun sortedSquares(nums: IntArray): IntArray {
        var n = nums.count()
        var ans = IntArray(n)
        var i = 0
        var j = n - 1
        var k = n - 1
        while (i <= j) {
            val x = nums[i] * nums[i]
            val y = nums[j] * nums[j]
            if (x > y) {
                ans[k--] = x
                i++
            } else {
                ans[k--] = y
                j--
            }
        }
        return ans
    }
}