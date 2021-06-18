class Solution {
	func longestConsecutive(_ nums: [Int]) -> Int {
		let st = Set(nums)
		var ans = 0
		for ele in st {
			if st.contains(ele - 1) == false {
				var (currentNumber, currentAnswer) = (ele, 1)
				while st.contains(currentNumber + 1) {
					currentNumber += 1
					currentAnswer += 1
				}
				ans = max(ans, currentAnswer)
			}
		}
		return ans
	}
}
