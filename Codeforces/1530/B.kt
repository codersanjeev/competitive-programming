private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }

val dx = listOf(-1, -1, -1, 0, 0, 1, 1, 1)
val dy = listOf(-1, 0, 1, -1, 1, -1, 0, 1)

fun safe(i: Int, j: Int, n: Int, m: Int) = i >= 0 && j >= 0 && i < n && j < m

fun good(ans: Array<IntArray>, i: Int, j: Int, n: Int, m: Int): Boolean {
    if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
        for (k in dx.indices) {
            val (x, y) = listOf(i + dx[k], j + dy[k])
            if (safe(x, y, n, m) && ans[x][y] == 1) return false
        }
        return true
    }
    return false
}

fun main() {
    val T = readInt()
    repeat(T) {
        val NM = readInts()
        val ans = Array(NM[0]) { IntArray(NM[1]) { 0 } }
        for (i in ans.indices) {
            for (j in ans[0].indices) {
                if (good(ans, i, j, NM[0], NM[1])) {
                    ans[i][j] = 1
                }
                print(ans[i][j])
            }
            println()
        }
        println()
    }
}