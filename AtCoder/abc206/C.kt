private fun readLn() = readLine()!!
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val n = readInt()
    val arr = readInts()
    var ans = 0L
    val mp = hashMapOf<Int, Int>()
    for (i in arr.indices) {
        val ele = arr[i]
        ans += i - mp.getOrDefault(ele, 0)
        mp[ele] = mp.getOrDefault(ele, 0) + 1
    }
    print(ans)
}