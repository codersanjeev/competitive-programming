class Solution {
    fun kWeakestRows(mat: Array<IntArray>, k: Int): IntArray {
        val (n, m) = listOf(mat.count(), mat[0].count())
        var st = mutableSetOf<Pair<Int, Int>>()
        for (i in 0 until n) {
        	var curr = mat[i].sum()
        	st.add(Pair<Int, Int>(curr, i))
        }
        st = st.sortedWith(compareBy({ it.first }, { it.second })).toMutableSet()
        val ans = mutableListOf<Int>()
        var cnt = k
        st.forEach { ele ->
        	if (cnt > 0) {
                ans.add(ele.second)
            }
        	cnt--
        }
        return ans.toIntArray()
    }
}