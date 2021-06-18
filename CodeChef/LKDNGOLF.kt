private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val T = readInt()
    for (i in 0 until T) {
        val (N, x, k) = readInts()
        when {
            x % k == 0 || (N + 1 - x) % k == 0 -> println("YES")
            else -> println("NO")
        }
    }
}