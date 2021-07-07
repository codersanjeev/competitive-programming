class Solution {
	private func lowerBound(_ arr: [Int], _ ele: Int) -> Int {
		var (lo, hi, ans) = (0, arr.count - 1, 0)
		while lo <= hi {
			let mid = lo + (hi - lo) / 2
			if arr[mid] < ele {
				ans = mid + 1
				lo = mid + 1
			} else {
				hi = mid - 1
			}
		}
		return ans
	}
	
	private func good(_ matrix: [[Int]], _ ele: Int, _ k: Int) -> Bool {
		var cnt = 0
		for row in matrix {
			cnt += lowerBound(row, ele)
		}
		return cnt < k
	}
	
	func kthSmallest(_ matrix: [[Int]], _ k: Int) -> Int {
		var (lo, hi, ans) = (matrix[0][0], matrix.last?.last ?? 0, 0)
		while lo <= hi {
			let mid = lo + (hi - lo) / 2
			if good(matrix, mid, k) {
				ans = mid
				lo = mid + 1
			} else {
				hi = mid - 1
			}
		}
		return ans
	}
}