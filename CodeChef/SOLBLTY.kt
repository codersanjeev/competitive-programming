private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args: Array<String>) {
    val T = readInt()
    for (i in 0 until T) {
        val (X, A, B) = readInts()
        println((A + (100 - X) * B) * 10)
    }
}