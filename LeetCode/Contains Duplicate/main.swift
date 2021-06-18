class Solution {
    func containsDuplicate(_ arr: [Int]) -> Bool {
        let nums = arr.sorted()
        let n = nums.count
        if (n == 0) {
            return false
        }
        for i in 0..<n - 1 {
            if (nums[i] == nums[i + 1]) {
                return true
            }
        }
        return false
    }
}