private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    var tc = readInt()
    while (tc > 0) {
        val s = readLn()
        val n = s.length
        var ans = 0
        for (i in 0 until n) {
            if (s[i] == 'w') {
                ans++
            }
        }
        var i = 0
        while (i < n - 1) {
            if (s[i] == 'v' && s[i + 1] == 'v') {
                ans++
                i++
            }
            i++
        }
        println(ans)
        tc--
    }
}
