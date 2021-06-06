class Solution {
    fun longestConsecutive(nums: IntArray): Int {
        val st = nums.toSet()
        var ans = 0
        for (ele in nums) {
            if (!st.contains(ele - 1)) {
                var (currentNumber, currentAnswer) = arrayOf(ele, 1)
                while (st.contains(currentNumber + 1)) {
                    ++currentNumber
                    ++currentAnswer
                }
                ans = ans.coerceAtLeast(currentAnswer)
            }
        }
        return ans
    }
}