import kotlin.math.max

private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readLongs() = readLns().map { it.toLong() }

fun main() {
    val n = readInt()
    var arr = readLongs()
    arr = arr.sorted()
    var ans = 1L
    val mod = (1e9 + 7).toLong()
    for (i in arr.indices) {
        ans = ans.times(max(0L, arr[i] - i)).rem(mod)
    }
    print(ans)
}