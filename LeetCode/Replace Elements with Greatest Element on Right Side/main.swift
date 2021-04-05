class Solution {
    func replaceElements(_ arr: [Int]) -> [Int] {
        var ans = arr
        let n = arr.count
        var mx = arr[n - 1]
        ans[n - 1] = -1
        for i in stride(from: n - 2, through: 0, by: -1) {
            let temp = ans[i]
            ans[i] = mx
            mx = max(mx, temp)
        }
        return ans
    }
}