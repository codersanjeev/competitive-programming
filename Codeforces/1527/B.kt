private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()

fun main() {
    val T = readInt()
    for (t in 1..T) {
        val N = readInt()
        val S = readLn()
        val zeros = S.count { it == '0' }
        var flips = 0
        for (i in 0 until N / 2) {
            if (S[i] != S[N - i - 1]) ++flips
        }
        when (flips) {
            0 -> println(if (zeros % 2 == 0 || zeros == 1) "BOB\n" else "ALICE\n")
            1 -> println(if (zeros == 2) "DRAW\n" else "ALICE\n")
            else -> println("ALICE\n")
        }
    }
}