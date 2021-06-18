fun main() {
    val arr = MutableList(0) { 0 }
    for (cnt in 1..9) {
        var ch = '1'
        while (ch <= '9') {
            val s = ch.toString().repeat(cnt)
            arr.add(s.toInt())
            ch++
        }
    }
    arr.sort()
    val T = readLine()?.toInt() ?: 1
    for (t in 1..T) {
        val n = readLine()?.toInt() ?: 1
        var (lo, hi, ans) = arrayOf(0, arr.size - 1, 0)
        while (lo <= hi) {
            val mid = lo + (hi - lo) / 2
            if (arr[mid] <= n) {
                ans = mid
                lo = mid + 1
            } else {
                hi = mid - 1
            }
        }
        println(ans + 1)
    }
}




