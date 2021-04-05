class Solution {
    func sumZero(_ n: Int) -> [Int] {
        if (n == 1) {
            return [0]
        }
        var ans = [Int]()
        var curr = 0
        for i in 1..<n {
            ans.append(i)
            curr += i
        }
        ans.append(curr * -1)
        return ans
    }
}