class Solution {
    func minPartitions(_ s: String) -> Int {
        var ans = 0
        s.forEach { ch in
            ans = max(ans, Int(ch.asciiValue! - Character("0").asciiValue!))
        }
        return ans
    }
}