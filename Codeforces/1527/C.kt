import kotlin.math.log2

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()

//private fun readInts() = readLn().split(" ").map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readLn().split(" ").map { it.toLong() }

fun main(args: Array<String>) {
    val T = readInt()
    for (t in 1..T) {
        val N = readLong()
        var ans = 0L
        val mp = hashMapOf<Long, Long>()
        val arr = readLongs()
        for (i in 1..N) {
            val ele = arr[i.toInt() - 1]
            ans += (N - i + 1) * mp.getOrDefault(ele, 0)
            mp[ele] = mp.getOrDefault(ele, 0) + i
        }
        println(ans)
    }
}