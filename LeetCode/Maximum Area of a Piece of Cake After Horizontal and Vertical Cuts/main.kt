class Solution {
    fun maxArea(h: Int, w: Int, H: IntArray, V: IntArray): Int {
        var horizontal = H.toCollection(ArrayList())
        var vertical = V.toCollection(ArrayList())
        horizontal.add(0)
        horizontal.add(h)
        vertical.add(0)
        vertical.add(w)
        horizontal.sort()
        vertical.sort()
        var (maxHorizontalDiff, maxVerticalDiff) = arrayOf(0L, 0L)
        for (i in 1 until horizontal.size) {
            maxHorizontalDiff = maxHorizontalDiff.coerceAtLeast((horizontal[i] - horizontal[i - 1]).toLong())
        }
        for (i in 1 until vertical.size) {
            maxVerticalDiff = maxVerticalDiff.coerceAtLeast((vertical[i] - vertical[i - 1]).toLong())
        }
        return (maxHorizontalDiff * maxVerticalDiff).rem(1000000007L).toInt()
    }
}