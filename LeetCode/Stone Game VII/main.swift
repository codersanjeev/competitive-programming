class Solution {
	private var dp = [[Int]]()
	
	private func solve(_ stones: [Int], _ i: Int, _ j: Int, _ score: Int) -> Int {
		if i == j { return 0 }
		if dp[i][j] != -1 { return dp[i][j] }
		let a = score - stones[i] - solve(stones, i + 1, j, score - stones[i])
		let b = score - stones[j] - solve(stones, i, j - 1, score - stones[j])
		dp[i][j] = max(a, b)
		return dp[i][j]
	}
	
	func stoneGameVII(_ stones: [Int]) -> Int {
		dp = [[Int]](
            repeating: [Int](
                repeating: -1, 
                count: stones.count
            ), 
            count: stones.count
        )
		return solve(stones, 0, stones.count - 1, stones.reduce(0, +))
	}
}