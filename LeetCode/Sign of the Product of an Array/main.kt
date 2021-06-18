class Solution {
    fun arraySign(nums: IntArray): Int {
        var negativeCount = 0
        var hasZeros = false
        nums.forEach { num ->
            if (num == 0) {
                hasZeros = true
            } else if (num < 0) {
                negativeCount += 1
            }
        }
        if (hasZeros) {
            return 0
        } else {
            return if (negativeCount % 2 == 0) 1 else -1
        }
    }
}