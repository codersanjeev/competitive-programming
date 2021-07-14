import kotlin.math.ceil
import kotlin.math.sqrt

private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readDouble() = readLn().toDouble()

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readDouble()
        println(ceil(sqrt(n)).toInt())
    }
}