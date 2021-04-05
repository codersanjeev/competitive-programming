class Solution {
    fun squareIsWhite(s: String): Boolean {
		val a = s[0] - 'a'
        val b = s[1] - '0'
        return (a + b) % 2 == 0
    }
}