class Solution {
    func oddCells(_ n: Int, _ m: Int, _ indices: [[Int]]) -> Int {
        var arr = Array<Array<Int>>(repeating: Array<Int>(repeating: 0, count: m), count: n)
        indices.forEach { xy in
            let x = xy[0]
            let y = xy[1]
            for i in 0..<n {
                arr[i][y] += 1
            }
            for j in 0..<m {
                arr[x][j] += 1
            }
        }
        var ans = 0
        arr.forEach { row in 
            row.forEach { ele in
                if (ele % 2 == 1) {
                    ans += 1
                }
            }
        }
        return ans
    }
}