class Solution {
    private fun isSame(word: String, pattern: String): Boolean {
        val (wordMap, patternMap) = listOf(hashMapOf<Char, Char>(), hashMapOf<Char, Char>())
        for (i in word.indices) {
            val (w, p) = arrayOf(word[i], pattern[i])
            if (!wordMap.containsKey(w)) wordMap[w] = p
            if (!patternMap.containsKey(p)) patternMap[p] = w
            if (wordMap[w] != p || patternMap[p] != w) return false
        }
        return true
    }

    fun findAndReplacePattern(words: Array<String>, pattern: String): List<String> {
        val ans = mutableListOf<String>()
        words.forEach { word ->
            if (isSame(word, pattern)) {
                ans.add(word)
            }
        }
        return ans
    }
}