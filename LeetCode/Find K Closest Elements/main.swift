class Solution {
	func findClosestElements(_ arr: [Int], _ k: Int, _ x: Int) -> [Int] {
		let ans = arr.sorted {
			abs($0 - x) < abs($1 - x)
		}
		return ans[0..<k].sorted()
	}
}
