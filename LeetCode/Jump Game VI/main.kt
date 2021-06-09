class Solution {
    fun maxResult(arr: IntArray, k: Int): Int {
        var q = ArrayDeque<Int>()
        var nums = arr.toMutableList()
        for (i in nums.indices) {
            nums[i] += if (q.isEmpty()) 0 else nums[q.first()]
            while (q.isNotEmpty() && nums[q.last()] < nums[i]) {
                q.removeLast()
            }
            q.add(i)
            while (q.isNotEmpty() && i - q.first() + 1 > k) {
                q.removeFirst()
            }
        }
        return nums.last()
    }
}
