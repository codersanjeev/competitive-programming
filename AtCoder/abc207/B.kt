import kotlin.math.ceil

private fun readLn() = readLine()!!
private fun readLns() = readLn().split(" ")
private fun readDoubles() = readLns().map { it.toDouble() }

fun main() {
    val arr = readDoubles()
    val den = (arr[2] * arr[3]) - arr[1]
    if (den <= 0) {
        print(-1)
    } else {
        print(ceil(arr[0] / den).toInt())
    }
}