class Solution {
    func rotate(_ matrix: inout [[Int]]) {
        let len = matrix.count
        for i in 0..<len {
            for j in 0..<i {
                let temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp
            }
        }
        for i in 0..<len {
            matrix[i] = matrix[i].reversed()
        }
    }
}