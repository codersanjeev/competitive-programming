private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readInts() = readLn().split(" ").map { it.toInt() }

fun main() {
    val T = readInt()
    for (t in 0 until T) {
        val n = readInt()
        val arr = readInts()
        val perm = MutableList(n) { 0 }
        for (i in perm.indices) perm[i] = i + 1
        when {
            arr == perm -> println(0)
            arr[0] == n && arr[n - 1] == 1 -> println(3)
            arr[0] == 1 || arr[n - 1] == n -> println(1)
            else -> println(2)
        }
    }
}