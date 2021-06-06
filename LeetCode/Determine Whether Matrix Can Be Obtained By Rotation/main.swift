class Solution {
	func findRotation(_ matrix: [[Int]], _ target: [[Int]]) -> Bool {
		var mat = matrix
		for _ in 0 ..< 4 {
			if mat == target { return true }
			rotate(&mat)
		}
		return false
	}
	
	private func rotate(_ matrix: inout [[Int]]) {
		let len = matrix.count
		for i in 0..<len {
			for j in 0..<i {
				let temp = matrix[i][j]
				matrix[i][j] = matrix[j][i]
				matrix[j][i] = temp
			}
		}
		for i in 0..<len {
			matrix[i] = matrix[i].reversed()
		}
	}
}
