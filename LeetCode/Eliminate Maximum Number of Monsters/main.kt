class Solution {
    fun eliminateMaximum(dist: IntArray, speed: IntArray): Int {
        val time = IntArray(dist.size)
        for (i in dist.indices) {
            time[i] = dist[i] / speed[i]
            if (dist[i].rem(speed[i]) > 0) ++time[i]
        }
        time.sort()
        var ans = 1
        for (i in time.indices) {
            if (ans > time[i]) {
                ans = i + 1
                break
            }
            ++ans
        }
        return ans - 1
    }
}