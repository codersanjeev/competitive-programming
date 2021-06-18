class Solution {
    fun maxPerformance(n: Int, speed: IntArray, efficiency: IntArray, k: Int): Int {
        var (ans, sum, mod) = arrayOf(0L, 0L, 1000000007L)
        val teamMembers = ArrayList<Pair<Int, Int>>()
        for (i in 0 until n) {
            val member = Pair(efficiency[i], speed[i])
            teamMembers.add(member)
        }
        teamMembers.sortByDescending { it.first }
        val heap = PriorityQueue<Int>()
        for (member in teamMembers) {
            heap.add(member.second)
            sum += member.second.toLong()
            if (heap.size > k) {
                sum -= (heap.poll()?.toInt() ?: 0)
            }
            ans = ans.coerceAtLeast(sum * member.first)
        }
        return (ans % mod).toInt()
    }
}
