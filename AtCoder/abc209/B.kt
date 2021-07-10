private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val (n, x) = readInts()
    val a = readInts()
    var y = 0
    for (i in a.indices) {
        y += a[i]
        if (i % 2 == 1) --y
    }
    if (y <= x) print("Yes")
    else print("No")
}