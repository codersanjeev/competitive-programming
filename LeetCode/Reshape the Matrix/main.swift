class Solution {
	func matrixReshape(_ mat: [[Int]], _ r: Int, _ c: Int) -> [[Int]] {
		let (n, m) = (mat.count, mat[0].count)
		if n * m != r * c {
			return mat
		}
		var temp = [Int]()
		for row in mat {
			for ele in row {
				temp.append(ele)
			}
		}
		var ans = [[Int]](repeating: [Int](repeating: -1, count: c), count: r)
		var k = 0
		for i in ans.indices {
			for j in ans[0].indices {
				ans[i][j] = temp[k]
				k += 1
			}
		}
		return ans
	}
}