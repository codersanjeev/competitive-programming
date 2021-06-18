private fun readLn() = readLine()!!
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readLns().map { it.toLong() }

fun main() {
    val T = readInt()
    for (t in 1..T) {
        val n = readInt()
        var arr = readInts()
        arr = arr.sorted()
        for (i in 0 until n) {
            print(arr[i].toString() + " " + arr[n + i].toString() + " ")
        }
        println()
    }
}