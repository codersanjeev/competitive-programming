fun main() {
    val T = readLine()?.toInt() ?: 1
    for (t in 1..T) {
        val n = readLine()?.toInt() ?: 1
        val s = readLine() ?: ""
        var x = ""
        x += s[0]
        for (i in 1 until n) {
            if (s[i] != s[i - 1]) x += s[i]
        }
        var good = true
        val seen = mutableSetOf<Char>()
        for (ch in x) {
            if (seen.contains(ch)) {
                good = false
                break
            }
            seen.add(ch)
        }
        if (good) println("YES\n") else println("NO\n")
    }
}