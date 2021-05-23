class Solution {
    private fun f(dist: IntArray, hour: Double, speed: Int): Boolean {
        var curr = 0.0
        for (i in dist.indices) {
            val delta = (dist[i] * 1.0) / speed
            if (i == dist.size - 1 && curr + delta <= hour) {
                return true
            }
            curr += Math.ceil(delta)
        }
        return curr <= hour
    }

    fun minSpeedOnTime(dist: IntArray, hour: Double): Int {
        var (lo, hi, ans) = arrayOf(0, 1e9.toInt(), -1)
        while (lo <= hi) {
            val mid = lo + (hi - lo) / 2
            if (f(dist, hour, mid)) {
                ans = mid
                hi = mid - 1
            } else {
                lo = mid + 1
            }
        }
        return ans
    }
}