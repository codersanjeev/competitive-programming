class Solution {
    
    func isEvenCount(_ num: Int) -> Bool {
        if (num >= 10 && num <= 99) {
            return true
        }
        if (num >= 1000 && num <= 9999) {
            return true
        }
        if (num == 100000) {
            return true
        }
        return false
    }
    
    func findNumbers(_ nums: [Int]) -> Int {
        var ans = 0
        nums.forEach { num in
            let curr = isEvenCount(num)
            if (curr == true) {
                ans += 1
            }
        }
        return ans
    }
}