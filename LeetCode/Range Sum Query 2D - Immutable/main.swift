class NumMatrix {
	
	private var prefixSum: [[Int]]
	
	init(_ matrix: [[Int]]) {
		let (n, m) = (matrix.count, matrix[0].count)
		prefixSum = [[Int]](repeating: [Int](repeating: 0, count: m + 1), count: n + 1)
		for i in 1...n {
			for j in 1...m {
				prefixSum[i][j] = matrix[i - 1][j - 1]
			}
		}
		for i in 1...n {
			for j in 1...m {
				prefixSum[i][j] += prefixSum[i][j - 1]
			}
 		}
		for j in 1...m {
			for i in 1...n {
				prefixSum[i][j] += prefixSum[i - 1][j]
			}
		}
	}
	
	func sumRegion(_ si: Int, _ sj: Int, _ ei: Int, _ ej: Int) -> Int {
		return prefixSum[ei + 1][ej + 1] - prefixSum[ei + 1][sj] - prefixSum[si][ej + 1] + prefixSum[si][sj]
	}
}
