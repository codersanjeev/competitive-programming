class Solution {
    func canBeEqual(_ A: [Int], _ B: [Int]) -> Bool {
        return A.sorted() == B.sorted()
    }
}