private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

private const val mod = (1e9 + 7).toLong()

private fun binpow(x: Long, y: Long): Long {
    if (y == 0L) return 1L
    var ans = binpow(x, y / 2) % mod
    ans = (ans * ans) % mod
    return when (y % 2) {
        0L -> ans
        else -> (ans * x) % mod
    }
}

fun main(args: Array<String>) {
    val T = readInt()
    for (i in 0 until T) {
        val N = readInt().toLong()
        println(binpow(2L, N - 1))
    }
}


