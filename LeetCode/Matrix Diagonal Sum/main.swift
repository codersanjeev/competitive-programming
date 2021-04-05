class Solution {
    func diagonalSum(_ mat: [[Int]]) -> Int {
        let n = mat.count
        var ans = 0
        for i in 0..<n {
            for j in 0..<n {
                if (i == j || i + j + 1 == n) {
                    ans += mat[i][j]
                }
            }
        }
        return ans
    }
}