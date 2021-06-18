class Solution {
    fun longestBeautifulSubstring(word: String): Int {
        val vowels = listOf('a', 'e', 'i', 'o', 'u')
        val freq = ArrayList<Pair<Char, Int>>()
        freq.add(Pair(word[0], 1))
        for (i in 1 until word.count()) {
            if (word[i] == freq.last().first) {
                val lastElement = freq.last()
                freq[freq.count() - 1] = Pair(lastElement.first, lastElement.second + 1)
            } else {
                freq.add(Pair(word[i], 1))
            }
        }
        val m = freq.count(); var answer = 0; var count = 0
        for (i in 0 until m) {
            var good = true; count = 0
            for (k in 0 until 5) {
                if (i + k < m && freq[i + k].first == vowels[k]) {
                    count += freq[i + k].second
                } else {
                    good = false
                    break
                }
            }
            if (good) answer = Math.max(answer, count)
        }
        return answer
    }
}