class Solution {
    fun canBeEqual(A: IntArray, B: IntArray): Boolean {
        return A.sorted() == B.sorted()
    }
}