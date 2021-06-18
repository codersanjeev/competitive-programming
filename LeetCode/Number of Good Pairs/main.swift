class Solution {
    func numIdenticalPairs(_ nums: [Int]) -> Int {
        var freq = [Int](repeating: 0, count: 101)
        nums.forEach { num in
            freq[num] += 1
        }
        var ans = 0
        freq.forEach { curr in
            ans += ((curr * (curr - 1)) / 2)
        }
        return ans
    }
}