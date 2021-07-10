private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInts() = readLns().map { it.toInt() }

private const val MAXN = 100005
private const val LOG = 20
private var adj = Array(MAXN) { ArrayList<Int>() }
private var depth = Array(MAXN) { 0 }
private var up = Array(MAXN) { Array(LOG) { 0 } }

private fun dfs(u: Int, par: Int) {
    for (v in adj[u]) {
        if (v == par) continue
        depth[v] = depth[u] + 1
        up[v][0] = u
        for (i in 1 until LOG) {
            up[v][i] = up[up[v][i - 1]][i - 1]
        }
        dfs(v, u)
    }
}

private fun lca(a: Int, b: Int): Int {
    var (u, v) = listOf(a, b)
    if (depth[u] < depth[v]) {
        val temp = u
        u = v
        v = temp
    }
    val (k, one) = listOf(depth[u] - depth[v], 1)
    for (i in LOG - 1 downTo 0) {
        if (k.and(one.shl(i)) != 0) u = up[u][i]
    }
    if (u == v) return u
    for (i in LOG - 1 downTo 0) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i]
            v = up[v][i]
        }
    }
    return up[u][0]
}

fun main() {
    val (n, q) = readInts()
    for (i in 1 until n) {
        val (u, v) = readInts()
        adj[u].add(v)
        adj[v].add(u)
    }
    dfs(1, 1)
    repeat(q) {
        val (u, v) = readInts()
        val w = lca(u, v)
        when ((depth[u] + depth[v] - 2 * depth[w]) % 2) {
            0 -> println("Town")
            1 -> println("Road")
        }
    }
}