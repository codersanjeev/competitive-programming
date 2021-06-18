class Solution {
    fun numIdenticalPairs(nums: IntArray): Int {
        var freq = IntArray(101)
        var ans = 0
        nums.forEach { num ->
            freq[num]++
        }
        freq.forEach { curr ->
            ans += (curr * (curr - 1) / 2)
        }
        return ans
    }
}
