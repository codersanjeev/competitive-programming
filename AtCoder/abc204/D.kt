private fun readLn() = readLine()!!
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val n = readInt()
    val arr = readInts()
    val sum = arr.sum()
    val dp = BooleanArray(sum + 1)
    dp[0] = true
    for (i in arr.indices) {
        for (rem in sum - arr[i] downTo 0) {
            if (dp[rem]) {
                dp[rem + arr[i]] = true
            }
        }
    }
    var ans = sum
    for (i in dp.indices) {
        if (dp[i]) {
            ans = ans.coerceAtMost(i.coerceAtLeast(sum - i))
        }
    }
    print(ans)
}
