private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }

private fun good(
    a: List<Int>,
    b: List<Int>,
    extra: Int
): Boolean {
    var contests = a.size + extra
    contests -= (contests / 4)
    var (myCount, myScore, oppCount, oppScore) = listOf(0, 0, 0, 0)
    for (i in 0 until extra) {
        if (myCount < contests) {
            myScore += 100
            ++myCount
        }
    }
    for (i in a.indices) {
        if (myCount < contests) {
            myScore += a[i]
            ++myCount
        }
        if (oppCount < contests) {
            oppScore += b[i]
            ++oppCount
        }
    }
    return myScore >= oppScore
}

fun main() {
    val T = readInt()
    repeat(T) {
        val N = readInt()
        val a = readInts().sortedDescending()
        val b = readInts().sortedDescending()
        var (lo, hi, ans) = listOf(0, 100000, 100000)
        while (lo <= hi) {
            val mid = lo + (hi - lo) / 2
            if (good(a, b, mid)) {
                ans = mid
                hi = mid - 1
            } else {
                lo = mid + 1
            }
        }
        println(ans)
    }
}