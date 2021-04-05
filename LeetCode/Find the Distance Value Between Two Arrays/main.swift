class Solution {
    func findTheDistanceValue(_ arr1: [Int], _ arr2: [Int], _ d: Int) -> Int {
        var ans = 0
        arr1.forEach { x in
            var good = true
            arr2.forEach { y in
                if (abs(x - y) <= d) {
                    good = false
                }
            }
            if (good) {
                ans += 1
            }
        }
        return ans
    }
}