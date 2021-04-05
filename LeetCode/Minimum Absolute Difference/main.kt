class Solution {
    fun minimumAbsDifference(arr: IntArray): List<List<Int>> {
        arr.sort()
        var n = arr.count(); var mn = Integer.MAX_VALUE
        for (i in 1 until n) {
            mn = Math.min(mn, arr[i] - arr[i - 1])
        }
        var ans = ArrayList<ArrayList<Int>>()
        for (i in 1 until n) {
            if (arr[i] - arr[i - 1] == mn) {
                var curr = ArrayList<Int>()
                curr.add(arr[i - 1])
                curr.add(arr[i])
                ans.add(curr)
            }
        }
        return ans
    }
}