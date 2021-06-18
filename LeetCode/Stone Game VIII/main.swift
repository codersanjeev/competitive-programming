class Solution {
	private func solve(_ stones: [Int], _ index: Int) -> Int {
		if index == stones.count - 2 {
			return stones.last ?? 0
		}
		let next = solve(stones, index + 1)
		return max(next, stones[index + 1] - next)
	}
	
	func stoneGameVIII(_ arr: [Int]) -> Int {
		var stones = arr
		for i in 1 ..< stones.count {
			stones[i] += stones[i - 1]
		}
		return solve(stones, 0)
	}
}
