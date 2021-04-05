class Solution {
    fun sumZero(n: Int): IntArray {
        var ans = mutableListOf<Int>()
        var curr = 0
        if (n == 1) {
            return IntArray(1) { 0 }
        }
        for (i in 1 until n) {
            ans.add(i)
            curr += i
        }
        ans.add(curr * -1)
        return ans.toIntArray()
    }
}