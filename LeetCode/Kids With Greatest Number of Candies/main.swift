class Solution {
    func kidsWithCandies(_ candies: [Int], _ extraCandies: Int) -> [Bool] {
        var ans = [Bool]()
        let curr = candies.max() ?? 0
        candies.forEach { candy in
            if (candy + extraCandies >= curr) {
                ans.append(true)
            } else {
                ans.append(false)
            }
        }
        return ans
    }
}