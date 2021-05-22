private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readInts() = readLn().split(" ").map { it.toInt() }

fun main(args: Array<String>) {
    val (a, b, c) = readInts()
    print(21 - a - b - c)
}
