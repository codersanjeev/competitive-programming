class Solution {
    fun fourSum(nums: IntArray, key: Int): List<List<Int>> {
        val ans = mutableListOf<List<Int>>()
        nums.sort()
        for (i in nums.indices) {
            for (j in i + 1 until nums.size) {
                val target = key - nums[i] - nums[j]
                var (lo, hi) = listOf(j + 1, nums.size - 1)
                while (lo < hi) {
                    val curr = nums[lo] + nums[hi]
                    when {
                        curr == target -> {
                            val temp = listOf(nums[i], nums[j], nums[lo], nums[hi])
                            ans.add(temp)
                            ++lo
                            --hi
                        }
                        curr > target -> --hi
                        else -> ++lo
                    }
                }
            }
        }
        return ans.makeUnique()
    }
}

fun MutableList<List<Int>>.makeUnique(): List<List<Int>> {
    return this.toSet().toList()
}