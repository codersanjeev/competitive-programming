class Solution {

    private fun shift(c: Char, x: Int): Char {
        return 'a' + (c - 'a' + x) % 26
    }

    fun replaceDigits(s: String): String {
        var answer = ""
        for (i in 1 until s.length step 2) {
            answer += s[i - 1]
            answer += shift(s[i - 1], s[i] - '0')
        }
        if (s.length % 2 == 1) {
            answer += s.last()
        }
        return answer
    }
}