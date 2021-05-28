import java.util.*

private fun readLn() = readLine()!!
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readLns().map { it.toLong() }

fun main() {
    val n = readInt()
    val arr = readLongs()
    var (ans, health) = arrayOf(0, 0L)
    val pq = PriorityQueue<Long>()
    for (ele in arr) {
        health += ele
        ++ans
        if (ele < 0) {
            pq.add(ele)
        }
        if (health < 0) {
            health -= pq.poll()
            --ans
        }
    }
    print(ans)
}