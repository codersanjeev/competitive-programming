class Solution {
    func smallerNumbersThanCurrent(_ nums: [Int]) -> [Int] {
        let n = nums.count
        var freq = [Int](repeating: 0, count: 101)
        var ans = [Int](repeating: 0, count: n)
        nums.forEach { num in
            freq[num] += 1
        }
        for i in 1..<101 {
            freq[i] += freq[i - 1]
        }
        for i in 0..<n {
            if (nums[i] == 0) {
                ans[i] = 0
            } else {
                ans[i] = freq[nums[i] - 1]
            }
        }
        return ans
    }
}