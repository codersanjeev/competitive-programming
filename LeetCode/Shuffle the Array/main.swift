class Solution {
    func shuffle(_ nums: [Int], _ n: Int) -> [Int] {
        var ans = [Int]()
        var i = 0, j = n
        for k in 0..<2*n {
            if (k % 2 == 0) {
                ans.append(nums[i])
                i += 1
            } else {
                ans.append(nums[j])
                j += 1
            }
        }
        return ans
    }
}