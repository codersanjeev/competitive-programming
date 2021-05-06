fun main() {
    val T = readLine()?.toInt() ?: 1
    for (t in 1..T) {
        val n = readLine()?.toInt() ?: 1
        when (n) {
            1 -> println(1)
            2 -> println(-1)
            else -> {
                val ans = Array(n) { IntArray(n) }
                var (value, flag) = arrayOf(1, 0)
                for (i in 0 until n) {
                    var j = flag
                    while (j < n) {
                        ans[i][j] = value++
                        j += 2
                    }
                    flag = flag.xor(1)
                }
                flag = 1
                for (i in 0 until n) {
                    var j = flag
                    while (j < n) {
                        ans[i][j] = value++
                        j += 2
                    }
                    flag = flag.xor(1)
                }
                ans.forEach { x ->
                    x.forEach { y ->
                        print(y)
                        print(" ")
                    }
                    println()
                }
            }
        }
    }
}