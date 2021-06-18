private fun readLn() = readLine()!!
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val n = readInt()
    val arr = readInts()
    var ans = 0
    for (ele in arr) {
        ans += Math.max(0, ele - 10)
    }
    print(ans)
}