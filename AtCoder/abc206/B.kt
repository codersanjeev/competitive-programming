private fun readLn() = readLine()!!
private fun readLong() = readLn().toLong()

fun main() {
    val n = readLong()
    var (lo, hi, ans) = arrayOf(0L, 1e5.toLong(), 1e5.toLong())
    while (lo <= hi) {
        val mid = lo + (hi - lo) / 2
        if ((mid * mid) + mid >= 2 * n) {
            ans = mid
            hi = mid - 1
        } else {
            lo = mid + 1
        }
    }
    print(ans)
}