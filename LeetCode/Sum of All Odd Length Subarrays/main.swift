class Solution {
    func sumOddLengthSubarrays(_ arr: [Int]) -> Int {
        let n = arr.count
        var ans = 0
        for i in 0..<n {
            ans += (((i + 1) * (n - i) + 1) / 2) * arr[i]
        }
        return ans
    }
}