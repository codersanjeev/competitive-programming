fun main() {
    val nk = readLine()?.split(" ")?.map { it.toLong() } ?: emptyList()
    var (n, k) = arrayOf(nk[0], nk[1])
    while (k > 0) {
        if (n % 200 == 0L) {
            n /= 200
        } else {
            val s = n.toString() + "200"
            n = s.toLong()
        }
        k--
    }
    print(n)
}