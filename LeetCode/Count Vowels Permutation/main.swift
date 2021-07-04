class Solution {
    func countVowelPermutation(_ n: Int) -> Int {
        let mod = Int64(1000000007)
        var dp = [[Int64]](repeating: [Int64](repeating: Int64(1), count: 5), count: n)
        for i in 1 ..< n {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
            dp[i][3] = dp[i - 1][2];
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        var ans = Int64(0)
        for ele in dp[n - 1] {
            ans = (ans + ele) % mod
        }
        return Int(ans)
    }
}