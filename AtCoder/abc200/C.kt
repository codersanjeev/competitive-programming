fun main() {
    val n = readLine()?.toLong() ?: 0L
    val mp = hashMapOf<Long, Long>()
    val arr = readLine()?.split(" ")?.map { it.toLong() } ?: emptyList()
    arr.forEach {
        val key = (it + 200) % 200
        mp[key] = mp.getOrDefault(key, 0L) + 1
    }
    var ans = 0L
    mp.forEach { (_, value) ->
        ans += (value * (value - 1)) / 2
    }
    print(ans)
}
