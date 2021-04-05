class Solution {
    
    fun isEvenCount(n: Int): Boolean {
        if (n >= 10 && n <= 99) return true
        if (n >= 1000 && n <= 9999) return true
        if (n == 100000) return true
        return false
    }
    
    fun findNumbers(nums: IntArray): Int {
        var ans = 0
        nums.forEach { num ->
            val curr = isEvenCount(num)
            if (curr == true) {
                ans++
            }
        }
        return ans
    }
}