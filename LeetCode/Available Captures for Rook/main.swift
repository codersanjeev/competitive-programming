class Solution {
    func numRookCaptures(_ board: [[Character]]) -> Int {
        var x = 0, y = 0, ans = 0
        for i in 0..<8 {
            for j in 0..<8 {
                if (board[i][j] == "R") {
                    x = i
                    y = j
                }
            }
        }
        let dx = [0, 0, 1, -1]
        let dy = [1, -1, 0, 0]
        for k in 0..<4 {
            var i = x, j = y
            while (i >= 0 && j >= 0 && i < 8 && j < 8) {
                if (board[i][j] == "p") {
                    ans += 1
                    break
                }
                if (board[i][j] != "." && board[i][j] != "R") {
                    break
                }
                i += dx[k]
                j += dy[k]
            }
        }
        return ans
    }
}