class Solution {
    func luckyNumbers (_ matrix: [[Int]]) -> [Int] {
        let n = matrix.count, m = matrix[0].count
        var x = Int.min, y = Int.max
        for i in 0..<n {
            var curr = Int.max
            for j in 0..<m {
                curr = min(curr, matrix[i][j])
            }
            x = max(x, curr)
        }
        for j in 0..<m {
            var curr = Int.min
            for i in 0..<n {
                curr = max(curr, matrix[i][j])
            }
            y = min(y, curr)
        }
        if (x == y) {
            return [x]    
        } else {
            return []
        }
    }
}