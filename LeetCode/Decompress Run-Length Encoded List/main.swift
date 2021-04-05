class Solution {
    func decompressRLElist(_ nums: [Int]) -> [Int] {
        var ans = [Int]()
        let n = nums.count
        for i in stride(from: 0, to: n - 1, by: 2) {
            let curr = [Int](repeating: nums[i + 1], count: nums[i])
            ans.append(contentsOf: curr)
        }
        return ans
    }
}