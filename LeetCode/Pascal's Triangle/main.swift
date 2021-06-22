class Solution {
	func generate(_ numRows: Int) -> [[Int]] {
		var ans = [[Int]]()
		if numRows == 0 { return ans }
		ans.append([1])
		for i in 1 ..< numRows {
			var curr = [Int](repeating: 1, count: i + 1)
			for j in 1 ..< i {
				curr[j] = ans[i - 1][j] + ans[i - 1][j - 1]
			}
			ans.append(curr)
		}
		return ans
	}
}
