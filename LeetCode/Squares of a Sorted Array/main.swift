class Solution {
    func sortedSquares(_ nums: [Int]) -> [Int] {
        let n = nums.count
        var ans = [Int]()
        for i in 0..<n {
            ans.append(0)
        }
        var i = 0, j = n - 1, k = n - 1
        while (i <= j) {
            let x = nums[i] * nums[i]
            let y = nums[j] * nums[j]
            if (x > y) {
                ans[k] = x
                i += 1
            } else {
                ans[k] = y
                j -= 1
            }
            k -= 1
        }
        return ans
    }
}