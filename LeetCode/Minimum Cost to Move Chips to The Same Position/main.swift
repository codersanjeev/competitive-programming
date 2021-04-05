class Solution {
    func minCostToMoveChips(_ position: [Int]) -> Int {
        var x = 0, y = 0
        position.forEach { pos in
            if (pos % 2 == 0) {
                x += 1
            } else {
                y += 1
            }
        }
        return min(x, y)
    }
}