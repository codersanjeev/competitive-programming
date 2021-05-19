private fun readLn() = readLine()!!
private fun readLong() = readLn().toLong()
private fun readLongs() = readLn().split(" ").map { it.toLong() }
private fun readInts() = readLn().split(" ").map { it.toInt() }

fun main(args: Array<String>) {
    val T = readLong()
    for (i in 0 until T) {
        val (N, M) = readInts()
        var ans = 0L
        val cnt = Array(N + 1) { 1L }
        for (b in 2 until N + 1) {
            ans += cnt[M % b]
            for (a in M % b until N + 1 step b) {
                ++cnt[a]
            }
        }
        println(ans)
    }
}
