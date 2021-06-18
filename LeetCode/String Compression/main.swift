class Solution {
    func compress(_ chars: inout [Character]) -> Int {
        let n = chars.count
        var ans = ""
        var curr = 1
        ans.append(chars[0])
        for i in 1..<n {
            if (ans.last != chars[i]) {
                if (curr > 1) {
                    ans += String(curr)
                }
                ans.append(chars[i])
                curr = 1
            } else {
                curr += 1
            }
        }
        if (curr > 1) {
            ans += String(curr)
        }
        let m = ans.count
        if (m <= n) {
            for i in 0..<m {
                chars[i] = ans.prefix(i + 1).last ?? "$"
            }
        }
        return m
    }
}