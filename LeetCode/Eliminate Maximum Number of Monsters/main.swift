class Solution {
    func eliminateMaximum(_ dist: [Int], _ speed: [Int]) -> Int {
        var time = [Int](repeating: 0, count: dist.count)
        for i in dist.indices {
            time[i] = dist[i] / speed[i]
            if dist[i] % speed[i] > 0 {
                time[i] += 1
            }
        }
        time.sort()
        var ans = 1
        for i in time.indices {
            if ans > time[i] {
                ans = i + 1
                break
            }
            ans += 1
        }
        return ans - 1
    }
}