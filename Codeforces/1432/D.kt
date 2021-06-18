private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var tc = readInt()
    while (tc > 0) {
        val (n, _, b) = readInts()
        val ans = Array(n) { 'a' }
        var ch = 'a'
        var i = 0
        while (i < b) {
            ans[i] = ch
            i++
            ch++
        }
        while (i < n) {
            ans[i] = ans[i - b]
            i++
        }
        ans.forEach {
            print(it)
        }
        println()
        tc--
    }
}