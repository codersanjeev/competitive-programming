private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readInts() = readLn().split(" ").map { it.toInt() }

fun main(args: Array<String>) {
    val n = readInt()
    val a = readInts()
    val b = readInts()
    val c = readInts()
    val mp = hashMapOf<Int, Int>()
    a.forEach { mp[it] = mp.getOrDefault(it, 0) + 1 }
    var ans = 0L
    c.forEach {
        ans += mp.getOrDefault(b[it - 1], 0).toLong()
    }
    print(ans)
}
