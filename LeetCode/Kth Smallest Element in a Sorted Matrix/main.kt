class Solution {
    private fun lowerBound(arr: IntArray, ele: Int): Int {
        var (lo, hi, ans) = listOf(0, arr.size - 1, 0)
        while (lo <= hi) {
            val mid = lo + (hi - lo) / 2
            if (arr[mid] < ele) {
                ans = mid + 1
                lo = mid + 1
            } else {
                hi = mid - 1
            }
        }
        return ans
    }

    private fun good(matrix: Array<IntArray>, ele: Int, k: Int): Boolean {
        var cnt = 0
        for (row in matrix) {
            cnt += lowerBound(row, ele)
        }
        return cnt < k
    }

    fun kthSmallest(matrix: Array<IntArray>, k: Int): Int {
        var (lo, hi, ans) = listOf(matrix[0][0], matrix.last().last(), 0)
        while (lo <= hi) {
            val mid = lo + (hi - lo) / 2
            if (good(matrix, mid, k)) {
                ans = mid
                lo = mid + 1
            } else {
                hi = mid - 1
            }
        }
        return ans
    }
}