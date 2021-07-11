import java.util.*

class Solution {
    private fun isSafe(i: Int, j: Int, m: Int, n: Int): Boolean {
        return i >= 0 && j >= 0 && i < m && j < n
    }

    private fun isBoundary(i: Int, j: Int, m: Int, n: Int): Boolean {
        return i == 0 || j == 0 || i == m - 1 || j == n - 1
    }

    fun nearestExit(maze: Array<CharArray>, entrance: IntArray): Int {
        val dx = listOf(0, 0, 1, -1)
        val dy = listOf(1, -1, 0, 0)
        val (m, n) = listOf(maze.size, maze[0].size)
        val visited = Array(m) { BooleanArray(n) { false } }
        val q: Queue<IntArray> = LinkedList()
        q.add(intArrayOf(entrance[0], entrance[1], 0))
        visited[entrance[0]][entrance[1]] = true
        while (q.isNotEmpty()) {
            val curr = q.poll()
            for (k in 0 until 4) {
                val (nx, ny) = listOf(curr[0] + dx[k], curr[1] + dy[k])
                if (!isSafe(nx, ny, m, n) || visited[nx][ny] || maze[nx][ny] == '+') {
                    continue
                }
                if (isBoundary(nx, ny, m, n) && maze[nx][ny] == '.' && !visited[nx][ny]) {
                    return curr[2] + 1
                }
                if (maze[nx][ny] == '.' && !visited[nx][ny]) {
                    visited[nx][ny] = true
                    q.add(intArrayOf(nx, ny, curr[2] + 1))
                }
            }
        }
        return -1
    }
}