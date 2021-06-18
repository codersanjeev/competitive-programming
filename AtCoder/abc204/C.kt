private fun readLn() = readLine()!!
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val (n, m) = readInts()
    val adj = ArrayList<ArrayList<Int>>()
    for (i in 0 until n) adj.add(ArrayList())
    for (i in 0 until m) {
        val (u, v) = readInts()
        adj[u - 1].add(v - 1)
    }
    var ans = 0
    for (u in 0 until n) {
        val visited = BooleanArray(n)
        ans += dfs(adj, visited, u)
    }
    print(ans)
}

private fun dfs(adj: ArrayList<ArrayList<Int>>, visited: BooleanArray, u: Int): Int {
    if (visited[u]) return 0
    visited[u] = true
    var ans = 1
    for (v in adj[u]) {
        ans += dfs(adj, visited, v)
    }
    return ans
}
