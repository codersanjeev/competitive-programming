class Solution {
    fun isNumber(s: String): Boolean {
        val number = Regex("^[+-]?((\\d+\\.?\\d*)|(\\d*\\.?\\d+))([eE][+-]?\\d+)?\$")
        return number.matches(s)
    }
}
