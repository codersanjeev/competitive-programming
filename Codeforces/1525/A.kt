private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()

private tailrec fun gcd(a: Int, b: Int): Int {
    return when (b) {
        0 -> a
        else -> gcd(b, a % b)
    }
}

fun main() {
    val t = readInt()
    for (i in 0 until t) {
        val n = readInt()
        var (x, y) = arrayOf(n, 100 - n)
        val g = gcd(x, y)
        x /= g
        y /= g
        println(x + y)
    }
}