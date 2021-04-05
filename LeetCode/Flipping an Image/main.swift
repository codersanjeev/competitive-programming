class Solution {
    func flipAndInvertImage(_ A: [[Int]]) -> [[Int]] {
        var ans = [[Int]]()
        for row in A {
            ans.append(row.reversed())
        }
        for i in 0..<A.count {
            for j in 0..<A.count {
                ans[i][j] ^= 1
            }
        }
        return ans
    }
}