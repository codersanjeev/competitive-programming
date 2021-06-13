class Solution {
    fun palindromePairs(words: Array<String>): List<List<Int>> {
        val ans = ArrayList<List<Int>>()
        val mp = HashMap<String, Int>()
        for (wordIndex in words.indices) mp[words[wordIndex]] = wordIndex
        for (wordIndex in words.indices) {
            for (len in 0 until words[wordIndex].length + 1) {
                val prefix = words[wordIndex].substring(0, len)
                val suffix = words[wordIndex].substring(len)
                if (prefix == prefix.reversed()) {
                    val suffixReversed = suffix.reversed()
                    if (mp.containsKey(suffixReversed) && mp[suffixReversed] != wordIndex) {
                        ans.add(listOf(mp[suffixReversed] ?: 0, wordIndex))
                    }
                }
                if (suffix == suffix.reversed()) {
                    val prefixReversed = prefix.reversed()
                    if (
                        mp.containsKey(prefixReversed) &&
                        mp[prefixReversed] != wordIndex &&
                        suffix.isNotEmpty()
                    ) {
                        ans.add(listOf(wordIndex, mp[prefixReversed] ?: 0))
                    }
                }
            }
        }
        return ans
    }
}