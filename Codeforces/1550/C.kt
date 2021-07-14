private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }

private fun bad(arr: MutableList<Int>): Boolean {
    for (i in arr.indices) {
        for (j in i + 1 until arr.size) {
            for (k in j + 1 until arr.size) {
                if (arr[i] >= arr[j] && arr[j] >= arr[k]) {
                    return true
                }
                if (arr[i] <= arr[j] && arr[j] <= arr[k]) {
                    return true
                }
            }
        }
    }
    return false
}

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val arr = readInts()
        var ans = 0
        for (i in arr.indices) {
            val temp = mutableListOf<Int>()
            for (j in i until arr.size) {
                temp.add(arr[j])
                if (bad(temp)) break
                ++ans
            }
        }
        println(ans)
    }
}