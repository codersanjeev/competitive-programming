class Solution {
    private let mod = 1000000007
    
    private func binpow(_ a: Int, _ b: Int) -> Int {
        var (x, y, ans) = (a % mod, b, 1)
        while y > 0 {
            if y % 2 == 1 {
                ans = (ans * x) % mod
            }
            x = (x * x) % mod
            y /= 2
        }
        return ans
    }
    
    func countGoodNumbers(_ n: Int) -> Int {
        let x = n / 2
        let y = n - x
        return (binpow(4, x) * binpow(5, y)) % mod
    }
}