class Solution {
    fun flipAndInvertImage(A: Array<IntArray>): Array<IntArray> {
        val n = A.count()
        for (i in 0 until n) {
            var lo = 0
            var hi = n - 1
            while (lo < hi) {
                val temp = A[i][lo]
                A[i][lo] = A[i][hi]
                A[i][hi] = temp
                lo++
                hi--
            }
        }
        for (i in 0 until n) {
            for (j in 0 until n) {
                A[i][j] = A[i][j].xor(1)
            }
        }
        return A;
    }
}