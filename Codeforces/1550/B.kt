private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val t = readInt()
    repeat(t) {
        val nab = readInts()
        val s = readLn()
        if (nab[2] >= 0) {
            println(nab[0] * (nab[1] + nab[2]))
        } else {
            var ops = 0
            for (i in 1 until s.length) {
                if (s[i] != s[i - 1]) ++ops
            }
            ops = (ops + 1) / 2
            println(nab[0] * nab[1] + (ops + 1) * nab[2])
        }
    }
}