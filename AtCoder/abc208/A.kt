private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInts() = readLns().map { it.toInt() }

private var dp = Array(101) { IntArray(1001) { -1 } }

private fun solve(a: Int, b: Int): Boolean {
    if (a == 0) return b == 0
    if (dp[a][b] != -1) return dp[a][b] == 1
    var res = false
    for (i in 1 until 7) {
        res = res.or(solve(a - 1, b - i))
    }
    dp[a][b] = if (res) 1 else 0
    return res
}

fun main() {
    val ab = readInts()
    when (solve(ab[0], ab[1])) {
        true -> print("Yes")
        false -> print("No")
    }
}