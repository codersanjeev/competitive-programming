private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readLongs() = readLns().map { it.toLong() }

fun main() {
    val nk = readLongs()
    val id = readLongs()
    val ans = LongArray(nk[0].toInt()) { nk[1] / nk[0] }
    var k = nk[1].rem(nk[0])
    val idMap = mutableMapOf<Long, Long>()
    for (i in id.indices) {
        idMap[id[i]] = i.toLong()
    }
    for (ele in id.sorted()) {
        if (k == 0L) break
        ++ans[idMap[ele]?.toInt() ?: 0]
        --k
    }
    for (ele in ans) println(ele)
}