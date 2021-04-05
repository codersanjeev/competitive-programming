class Solution {
    func countNegatives(_ grid: [[Int]]) -> Int {
        var ans = 0, n = grid.count, m = grid[0].count
        for i in 0..<n {
            var j = 0
            while (j < m) {
                if (grid[i][j] < 0) {
                    break
                }
                j += 1
            }
            ans += (m - j)
        }
        return ans
    }
}