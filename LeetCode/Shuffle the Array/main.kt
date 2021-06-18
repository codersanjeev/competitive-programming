class Solution {
    fun shuffle(nums: IntArray, n: Int): IntArray {
        var ans = IntArray(2 * n)
        var i = 0
        var j = n
        for (k in 0 until 2 * n) {
            if (k % 2 == 0) {
                ans[k] = nums[i]
                i++
            } else {
                ans[k] = nums[j]
                j++
            }
        }
        return ans
    }
}