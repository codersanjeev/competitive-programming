class Solution {
    func canFormArray(_ arr: [Int], _ pieces: [[Int]]) -> Bool {
        var mp = [Int: [Int]]()
        pieces.forEach { piece in
            mp[piece[0]] = piece
        }
        var n = arr.count, idx = 0, ans = true
        while (idx < n) {
            if let curr = mp[arr[idx]] {
                curr.forEach { ele in
                    if (ele != arr[idx]) {
                        ans = false
                    }
                    idx += 1
                }
            } else {
                return false
            }
            if (ans == false) {
                return false
            }
        }
        return idx == n
    }
}