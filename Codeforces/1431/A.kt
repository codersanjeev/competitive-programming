import java.util.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    var tc = readInt()
    while (tc > 0) {
        val n = readInt()
        val arr = readLongs()
        Collections.sort(arr)
        var ans = Long.MIN_VALUE
        for (i in 1..n) {
            val curr = arr[i - 1] * (n - i + 1)
            ans = Math.max(ans, curr)
        }
        println(ans)
        tc--
    }
}
