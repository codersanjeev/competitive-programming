class Solution {
    func arrayPairSum(_ A: [Int]) -> Int {
        var nums = A.sorted()
        var ans = 0, n = nums.count
        for i in 0..<n {
            if (i % 2 == 0) {
                ans += nums[i]
            }
        }
        return ans
    }
}