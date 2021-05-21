import kotlin.math.log2

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
//private fun readInts() = readLn().split(" ").map { it.toInt() }
//private fun readLong() = readLn().toLong()
//private fun readLongs() = readLn().split(" ").map { it.toLong() }

fun main(args: Array<String>) {
    val T = readInt()
    for (t in 1..T) {
        val N = readInt()
        var (one, b) = arrayOf(1, 29)
        while (N.and(one.shl(b)) == 0) b--
        println(one.shl(b) - 1)
    }
}