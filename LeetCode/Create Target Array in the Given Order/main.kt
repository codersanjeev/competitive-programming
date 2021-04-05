class Solution {
    
    fun insertAt(arr: IntArray, key: Int, index: Int): IntArray {
        val result = arr.toMutableList()
        result.add(index, key)
        return result.toIntArray()
    }
    
    fun createTargetArray(nums: IntArray, index: IntArray): IntArray {
        var ans = IntArray(0)
        val n = nums.count()
        for (i in 0 until n) {
            ans = insertAt(ans, nums[i], index[i])    
        }
        return ans
    }
}