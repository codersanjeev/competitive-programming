private fun readLn() = readLine()!!
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readLns().map { it.toLong() }

private var cache = hashMapOf<Int, Int>()
private var arr = arrayOf(
    11, 111, 1111, 11111,
    111111, 1111111, 11111111, 111111111
)

private fun check(n: Int): Boolean {
    if (n < 0) return false
    if (n == 0) return true
    for (ele in arr) {
        if (n % ele == 0) return true
    }
    val x = cache.getOrDefault(n, 0)
    if (x == -1) return false
    else if (x == 1) return true
    for (ele in arr) {
        if (check(n - ele)) {
            cache[n] = 1
            return true
        }
    }
    cache[n] = -1
    return false
}

fun main() {
    val T = readInt()
    for (t in 1..T) {
        val n = readInt()
        println(if (check(n)) "YES\n" else "NO\n")
    }
}