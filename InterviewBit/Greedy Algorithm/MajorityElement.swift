import Foundation

class Solution {
    func majorityElement(_ nums: [Int]) -> Int {

        var mp = [Int : Int]()
        for i in nums {
        if mp[i] == nil {
                mp[i] = 1
            }
            else {
                mp[i] = mp[i]! + 1
            }
        }
        for (i, j) in mp {
            if j > nums.count / 2 {
            return i
        }
    }
    return -1

}
}
