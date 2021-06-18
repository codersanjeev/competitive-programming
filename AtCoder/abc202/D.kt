private fun readLn() = readLine()!!
private fun readLongs() = readLn().split(" ").map { it.toLong() }

fun main(args: Array<String>) {
    var (a, b, k) = readLongs()
    val dp = Array(61) { Array(61) { 0L } }
    dp[0][0] = 1L
    for (i in 1 until 61) {
        dp[i][0] = 1L
        dp[i][i] = 1L
        for (j in 1 until i) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]
        }
    }
    val n = a + b
    for (i in 0 until n) {
        val cnt = dp[(a + b - 1).toInt()][b.toInt()]
        if (cnt >= k) {
            print("a")
            --a
        } else {
            print("b")
            --b
            k -= cnt
        }
    }
}
