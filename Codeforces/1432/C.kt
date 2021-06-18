private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var tc = readInt()
    while (tc > 0) {
        val n = readInt()
        val sum = readInts().reduce { x, y -> x + y }
        if (sum % n == 0) {
            println(sum / n)
        } else {
            println((sum / n) + 1)
        }
        tc--
    }
}