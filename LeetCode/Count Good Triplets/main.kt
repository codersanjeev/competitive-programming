class Solution {
    fun countGoodTriplets(arr: IntArray, a: Int, b: Int, c: Int): Int {
        val n = arr.count()
        var ans = 0
        for (i in 0 until n) {
            for (j in i + 1 until n) {
                if (Math.abs(arr[i] - arr[j]) > a) {
                    continue
                }
                for (k in j + 1 until n) {
                    if (Math.abs(arr[j] - arr[k]) <= b && Math.abs(arr[i] - arr[k]) <= c) {
                        ans++
                    }
                }
            }
        }
        return ans
    }
}