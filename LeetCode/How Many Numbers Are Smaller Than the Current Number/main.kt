class Solution {
    fun smallerNumbersThanCurrent(nums: IntArray): IntArray {
        val n = nums.count()
        var ans = IntArray(n)
        var freq = IntArray(101)
        nums.forEach { num -> 
            freq[num]++
        }
        for (i in 1 until 101) {
            freq[i] += freq[i - 1]
        }
        for (i in 0 until n) {
            if (nums[i] == 0) {
                ans[i] = 0
            } else {
                ans[i] = freq[nums[i] - 1]
            }
        }
        return ans
    }
}