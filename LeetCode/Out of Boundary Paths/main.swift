class Solution {
	
	private let dx = [0, 0, 1, -1]
	private let dy = [1, -1, 0, 0]
	private let mod = 1000000007
	private var dp = [[[Int]]](
		repeating: [[Int]](
			repeating: [Int](
				repeating: -1, 
				count: 51), 
			count: 51), 
		count: 51)
	
	func findPaths(_ m: Int, 
				   _ n: Int, 
				   _ maxMove: Int, 
				   _ startRow: Int, 
				   _ startColumn: Int
	) -> Int {
		if startRow < 0 || startColumn < 0 || startRow >= m || startColumn >= n {
			return 1
		}
		if maxMove == 0 { return 0 }
		if dp[maxMove][startRow][startColumn] != -1 { 
			return dp[maxMove][startRow][startColumn] 
		}
		var ans = 0
		for k in dx.indices {
			ans = (ans + findPaths(m, 
								   n, 
								   maxMove - 1, 
								   startRow + dx[k], 
								   startColumn + dy[k])
			) % mod
		}
		dp[maxMove][startRow][startColumn] = ans
		return ans
	}
}