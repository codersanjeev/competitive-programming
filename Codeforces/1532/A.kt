private fun readLn() = readLine() ?: " "
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    var t = readInt()
    while (t-- > 0) {
        val (a, b) = readInts()
        println(a + b)
    }
}