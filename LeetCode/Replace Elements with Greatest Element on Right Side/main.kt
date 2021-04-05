class Solution {
    fun replaceElements(arr: IntArray): IntArray {
        val n = arr.count()
        var mx = arr[n - 1]
        arr[n - 1] = -1
        for (i in n - 2 downTo 0) {
            val temp = arr[i]
            arr[i] = mx
            mx = Math.max(mx, temp)
        }
        return arr
    }
}