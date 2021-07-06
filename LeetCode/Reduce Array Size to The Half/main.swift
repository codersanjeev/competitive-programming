class Solution {
	func minSetSize(_ arr: [Int]) -> Int {
		var mp = [Int : Int]()
		for ele in arr {
			mp[ele] = (mp[ele] ?? 0) + 1
		}
		var ans = 0
		var freq = [[Int]]()
		for ele in mp {
			freq.append([ele.value, ele.key])
		}
		freq.sort { x, y in x[0] > y[0] }
		var (curr, index) = (arr.count, 0)
		while curr > arr.count / 2 {
			curr -= freq[index].first ?? 0
			ans += 1
			index += 1
		}
		return ans
	}
}