class Solution {
    
    fun makeRowZero(matrix: Array<IntArray>, i: Int, m: Int) {
        for (j in 0 until m) {
            matrix[i][j] = 0
        }
    }
    
    fun makeColumnZero(matrix: Array<IntArray>, j: Int, n: Int) {
        for (i in 0 until n) {
            matrix[i][j] = 0
        }
    }
    
    fun setZeroes(matrix: Array<IntArray>): Unit {
        var rowHasZero = false
        var columnHasZero = false
        val n = matrix.count()
        val m = matrix[0].count()
        
        for (i in 0 until n) {
            if (matrix[i][0] == 0) {
                columnHasZero = true
                break
            }
        }
        
        for (j in 0 until m) {
            if (matrix[0][j] == 0) {
                rowHasZero = true
                break
            }
        }
        
        for (i in 1 until n) {
            for (j in 1 until m) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0
                    matrix[i][0] = 0
                }
            }
        }
        
        for (i in 1 until n) {
            if (matrix[i][0] == 0) {
                makeRowZero(matrix, i, m)
            }
        }
        
        for (j in 1 until m) {
            if (matrix[0][j] == 0) {
                makeColumnZero(matrix, j, n)
            }
        }
        
        if (rowHasZero) {
            makeRowZero(matrix, 0, m)
        }
        
        if (columnHasZero) {
            makeColumnZero(matrix, 0, n)
        }
        
    }
}