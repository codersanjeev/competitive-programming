class Solution {
    func canMakeArithmeticProgression(_ arr: [Int]) -> Bool {
        var mx = arr.max() ?? 0, mn = arr.min() ?? 0, idx = 0, n = arr.count
        if ((mx - mn) % (n - 1) != 0) {
            return false
        }
        let d = (mx - mn) / (n - 1)
        while (idx < n) {
            if (arr.contains(mn) == false) {
                return false
            }
            mn += d
            idx += 1
        }
        return true
    }
}