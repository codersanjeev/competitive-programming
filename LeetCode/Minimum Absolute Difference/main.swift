class Solution {
    func minimumAbsDifference(_ A: [Int]) -> [[Int]] {
        var ans = [[Int]](), mn = Int.max, arr = A.sorted(), n = arr.count
        for i in 1..<n {
        	mn = min(mn, arr[i] - arr[i - 1])
        }
        for i in 1..<n {
        	if (arr[i] - arr[i - 1] == mn) {
        		var curr = [arr[i - 1], arr[i]]
        		ans.append(curr)
        	}
        }
        return ans
    }
}