class DSU(n: Int) {
    private var parent = IntArray(n) { -1 }
    private var rank = IntArray(n) { 1 }

    private fun find(u: Int): Int {
        return when (parent[u]) {
            -1 -> u
            else -> {
                parent[u] = find(parent[u])
                parent[u]
            }
        }
    }

    fun merge(u: Int, v: Int): Boolean {
        val a = find(u)
        val b = find(v)
        if (a != b) {
            if (rank[a] < rank[b]) {
                parent[a] = b
                rank[b] += rank[a]
            } else {
                parent[b] = a
                rank[a] += rank[b]
            }
            return true
        }
        return false
    }
}

class Solution {
    fun findRedundantConnection(edges: Array<IntArray>): IntArray {
        val dsu = DSU(edges.size)
        for (edge in edges) {
            if (!dsu.merge(edge[0] - 1, edge[1] - 1)) {
                return edge
            }
        }
        return IntArray(0)
    }
}