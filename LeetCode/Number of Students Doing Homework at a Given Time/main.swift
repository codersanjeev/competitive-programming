class Solution {
    func busyStudent(_ startTime: [Int], _ endTime: [Int], _ queryTime: Int) -> Int {
        var ans = Array<Int>(repeating: 0, count: 1002)
        let n = startTime.count
        for i in 0..<n {
            ans[startTime[i]] += 1
            ans[endTime[i] + 1] -= 1
        }
        for i in 1..<1002 {
            ans[i] += ans[i - 1]
        }
        return ans[queryTime]
    }
}