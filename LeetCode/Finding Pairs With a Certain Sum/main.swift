
class FindSumPairs {
	private var X: [Int]
	private var Y: [Int]
	private var mp: [Int:Int]
	
	init(_ nums1: [Int], _ nums2: [Int]) {
		self.X = nums1
		self.Y = nums2
		mp = [Int:Int]()
		Y.forEach {
			if let value = mp[$0] {
				mp[$0] = value + 1
			} else {
				mp[$0] = 1
			}
		}
	}
	
	func add(_ index: Int, _ val: Int) {
		let oldValue = Y[index]
		Y[index] += val
		let newValue = Y[index]
		if let value = mp[oldValue] {
			mp[oldValue] = max(value - 1, 0)
		}
		if let value = mp[newValue] {
			mp[newValue] = value + 1
		}
	}
	
	func count(_ target: Int) -> Int {
		var answer = 0
		X.forEach {
			answer += mp[target - $0] ?? 0
		}
		return answer
	}
}
