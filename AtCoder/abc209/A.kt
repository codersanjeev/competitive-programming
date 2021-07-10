private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val (a, b) = readInts()
    var ans = b - a + 1
    if (ans < 0) ans = 0
    print(ans)
}