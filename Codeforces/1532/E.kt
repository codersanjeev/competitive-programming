private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readLongs() = readLns().map { it.toLong() }

fun main() {
    val n = readInt()
    val arr = readLongs()
    var sum = arr.sum()
    val freq = hashMapOf<Long, Int>()
    for (ele in arr) freq[ele] = (freq[ele] ?: 0) + 1
    val ans = mutableListOf<Int>()
    for (i in arr.indices) {
        sum -= arr[i]
        freq[arr[i]] = (freq[arr[i]] ?: 0) - 1
        if (sum % 2 == 0L && (freq[sum / 2L] ?: 0) > 0) {
            ans.add(i + 1)
        }
        sum += arr[i]
        freq[arr[i]] = (freq[arr[i]] ?: 0) + 1
    }
    println(ans.size)
    for (ele in ans) print("$ele ")
}