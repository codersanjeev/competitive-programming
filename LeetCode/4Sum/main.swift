class Solution {
	func fourSum(_ arr: [Int], _ key: Int) -> [[Int]] {
		var ans = [[Int]]()
		let nums = arr.sorted()
		for i in nums.indices {
			for j in i + 1 ..< nums.count {
				let target = key - nums[i] - nums[j]
				var (lo, hi) = (j + 1, nums.count - 1)
				while lo < hi {
					let curr = nums[lo] + nums[hi]
					if curr == target {
						let temp = [nums[i], nums[j], nums[lo], nums[hi]]
						ans.append(temp)
						lo += 1
						hi -= 1
					} else if curr > target {
						hi -= 1
					} else {
						lo += 1
					}
				}
			}
		}
		return ans.makeUnique()
	}
}

extension Sequence where Iterator.Element: Hashable {
    func makeUnique() -> [Iterator.Element] {
        var ans = Set<Iterator.Element>()
        return self.filter { ans.insert($0).inserted }
    }
}