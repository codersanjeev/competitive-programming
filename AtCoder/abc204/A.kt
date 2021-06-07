private fun readLn() = readLine()!!
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val xy = readInts()
    if (xy[0] == xy[1]) {
        print(xy[0])
    } else {
        print(3 - xy.sum())
    }
}