class Solution {
	func maxScore(_ cardPoints: [Int], _ k: Int) -> Int {
		var ans = 0, curr = 0
		for i in 0..<k {
			curr += cardPoints[i]
		}
		ans = curr
		var i = cardPoints.count - 1, j = k - 1
		while (j >= 0) {
			curr -= cardPoints[j]
			curr += cardPoints[i]
			ans = max(ans, curr)
			i -= 1
			j -= 1
		}
		return ans
	}
}
