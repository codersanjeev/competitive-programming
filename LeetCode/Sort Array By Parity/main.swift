class Solution {
    func sortArrayByParity(_ A: [Int]) -> [Int] {
        return A.sorted { ($0 % 2 == 1 && $1 % 2 == 0) == false }
    }
}