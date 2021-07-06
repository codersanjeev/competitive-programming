class Solution {
    fun minSetSize(arr: IntArray): Int {
        val mp = hashMapOf<Int, Int>()
        for (ele in arr) mp[ele] = (mp[ele] ?: 0) + 1
        var ans = 0
        val freq = mutableListOf<Pair<Int, Int>>()
        for (ele in mp) freq.add(Pair(ele.value, ele.key))
        freq.sortWith { x, y -> y.first - x.first }
        var (curr, index) = listOf(arr.size, 0)
        while (curr > arr.size / 2) {
            curr -= freq[index].first
            ++ans
            ++index
        }
        return ans
    }
}