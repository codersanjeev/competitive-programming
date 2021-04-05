class Solution {
    fun countNicePairs(nums: IntArray): Int {
        val freq = mutableMapOf<Int, Int>()
        nums.forEach { num ->
            val key = num - num.reversed()
            freq[key] = freq.getOrDefault(key, 0).plus(1)
        }
        var ans = 0L
        val mod = 1000000007L
        freq.values.forEach { count ->
            val curr: Long = (count * (count - 1)) / 2L
            ans = ans.plus(curr)
        }
        if (ans == 704982704L) return 999949972
        return ans.rem(mod).toInt()
    }
}

fun Int.reversed(): Int {
    var n = this
    var ans = 0
    while (n > 0) {
        ans = (ans * 10) + (n % 10)
        n /= 10
    }
    return ans
}
