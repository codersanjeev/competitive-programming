class Solution {
    fun busyStudent(startTime: IntArray, endTime: IntArray, queryTime: Int): Int {
        var ans = IntArray(1002) { 0 }
        val n = startTime.count()
        for (i in 0 until n) {
            ans[startTime[i]]++
            ans[endTime[i] + 1]--
        }
        for (i in 1 until 1002) {
            ans[i] += ans[i - 1]
        }
        return ans[queryTime]
    }
}