fun main() {
    val s = readLine()!!
    var ans = 0
    for (i in 0 until 10000) {
        var curr = i.toString()
        while (curr.length < 4) curr = "0$curr"
        var good = true
        for (d in 0 until 10) {
            if (s[d] == 'o') {
                var cnt = 0
                curr.forEach {
                    if (it - '0' == d) ++cnt
                }
                if (cnt == 0) good = false
            } else if (s[d] == 'x') {
                curr.forEach {
                    if (it - '0' == d) good = false
                }
            }
        }
        if (good) ++ans
    }
    print(ans)
}
