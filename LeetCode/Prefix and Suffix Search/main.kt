class WordFilter(words: Array<String>) {

    private val mp = mutableMapOf<String, Int>()

    init {
        for (i in 0 until words.count()) {
            val prefix = mutableListOf<String>()
            val suffix = mutableListOf<String>()
            for (j in 0 until words[i].count() + 1) {
                prefix.add(words[i].substring(0, j))
                suffix.add(words[i].substring(j))
            }
            prefix.forEach { p ->
                suffix.forEach { s ->
                    val key = "$p*$s"
                    mp[key] = Math.max(mp.getOrDefault(key, 0), i)
                }
            }
        }
    }

    fun f(prefix: String, suffix: String): Int {
        val key = "$prefix*$suffix"
        return mp.getOrDefault(key, -1)
    }

}

/**
 * Your WordFilter object will be instantiated and called as such:
 * var obj = WordFilter(words)
 * var param_1 = obj.f(prefix,suffix)
 */