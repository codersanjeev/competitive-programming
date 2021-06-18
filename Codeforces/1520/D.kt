fun main() {
    val t = readLine()?.toLong() ?: 1L
    for (i in 1..t) {
        val n = readLine()?.toLong() ?: 1L
        val arr = readLine()?.split(" ")?.map { it.toLong() } ?: emptyList()
        var ans = 0L
        val mp = hashMapOf<Long, Long>()
        for (j in arr.indices) {
            val temp = mp.getOrDefault(arr[j] - j, 0L)
            ans += temp
            mp[arr[j] - j] = temp + 1
        }
        println(ans)
    }
}