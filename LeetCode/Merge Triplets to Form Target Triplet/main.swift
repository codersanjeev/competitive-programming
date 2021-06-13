class Solution {
	func mergeTriplets(_ triplets: [[Int]], _ target: [Int]) -> Bool {
		var start = [Int](repeating: 0, count: 3)
		for triplet in triplets {
			if triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2] {
				for i in 0 ..< 3 {
					start[i] = max(start[i], triplet[i])
				}
			}
		}
		return start == target
	}
}
