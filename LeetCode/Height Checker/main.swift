class Solution {
    func heightChecker(_ heights: [Int]) -> Int {
        let sortedHeights = heights.sorted()
        var n = heights.count, ans = 0
        for i in 0..<n {
            if (heights[i] != sortedHeights[i]) {
                ans += 1
            }
        }
        return ans
    }
}