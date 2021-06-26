private fun readLn() = readLine()!!
private fun readLns() = readLn().split(" ")
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    var arr = readInts()
    arr = arr.sorted()
    print(arr[1] + arr[2])
}