class Solution {
    
    func makeColumnZero(_ matrix: inout [[Int]], _ j: Int, _ n: Int) {
        for i in 0..<n {
            matrix[i][j] = 0
        }
    }
    
    func makeRowZero(_ matrix: inout [[Int]], _ i: Int, _ m: Int) {
        for j in 0..<m {
            matrix[i][j] = 0
        }
    }
    
    func setZeroes(_ matrix: inout [[Int]]) {
        let n = matrix.count, m = matrix[0].count
        var rowHasZeros = false, columnHasZeros = false
        for i in 0..<n {
            if (matrix[i][0] == 0) {
                columnHasZeros = true
                break
            }
        }
        for j in 0..<m {
            if (matrix[0][j] == 0) {
                rowHasZeros = true
                break
            }
        }
        for i in 1..<n {
            for j in 1..<m {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0
                    matrix[0][j] = 0
                }
            }
        }
        for i in 1..<n {
            if (matrix[i][0] == 0) {
                makeRowZero(&matrix, i, m)
            }
        }
        for j in 1..<m {
            if (matrix[0][j] == 0) {
                makeColumnZero(&matrix, j, n)
            }
        }
        if(rowHasZeros) {
            makeRowZero(&matrix, 0, m)
        }
        if (columnHasZeros) {
            makeColumnZero(&matrix, 0, n)
        }
    }
}