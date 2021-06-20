class Solution {
    fun minDifference(nums: IntArray, queries: Array<IntArray>): IntArray {
        val prefix = Array(nums.size) { IntArray(101) { 0 } }
        val freq = IntArray(101) { 0 }
        for (i in nums.indices) {
            freq[nums[i]]++
            for (j in freq.indices) {
                prefix[i][j] = freq[j]
            }
        }
        val ans = mutableListOf<Int>()
        for (query in queries) {
            val (l, r) = arrayOf(query[0], query[1])
            val arr = mutableListOf<Int>()
            for (j in freq.indices) {
                if (prefix[r][j] > (if (l - 1 >= 0) prefix[l - 1][j] else 0)) {
                    arr.add(j)
                }
            }
            var curr = Int.MAX_VALUE
            for (i in 1 until arr.size) {
                curr = curr.coerceAtMost(arr[i] - arr[i - 1])
            }
            ans.add(if (curr == Int.MAX_VALUE) -1 else curr)
        }
        return ans.toIntArray()
    }
}