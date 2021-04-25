class Solution {
    fun sumBase(n: Int, k: Int): Int {
        return n
            .toString(k)
            .map(Character::getNumericValue)
            .sum()
    }
}