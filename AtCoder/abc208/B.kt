private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()

fun main() {
    var n = readInt()
    val coins = mutableListOf<Int>()
    var (coin, ans) = listOf(1, 0)
    for (i in 1 until 11) {
        coin *= i
        for (j in 1 until 101) {
            coins.add(coin)
        }
    }
    for (ele in coins.reversed()) {
        if (ele <= n) {
            n -= ele
            ++ans
        }
    }
    print(ans)
}