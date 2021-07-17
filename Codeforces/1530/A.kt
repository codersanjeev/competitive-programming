import kotlin.math.max

private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()

fun main() {
    val T = readInt()
    repeat(T) {
        var N = readInt()
        var ans = 1
        while (N > 0) {
            ans = max(ans, N % 10)
            N /= 10
        }
        println(ans)
    }
}