class Solution {
    fun countCharacters(words: Array<String>, chars: String): Int {
		var freq = IntArray(26) { 0 }
		var ans = 0
		chars.forEach { ch ->
			freq[ch - 'a']++
		}
		words.forEach { word ->
			var cnt = IntArray(26) { 0 }
			word.forEach { ch ->
				cnt[ch - 'a']++
			}
			var good = true
			for (i in 0 until 26) {
				if (cnt[i] > freq[i]) {
					good = false;
					break;
				}
			}
			if (good) {
				ans += word.count()
			}
		}
		return ans        
    }
}