class Solution {
	func isPossible(_ arr: [Int]) -> Bool {
		var target: [Int64] = arr.map({ Int64($0) ?? Int64(0) })
		var sum = Int64(0), index = maxElementIndex(target)
		target.forEach { sum += $0 }
		while (sum > Int64(1) && target[index] > sum / Int64(2)) {
			sum -= target[index]
			if (sum <= 1) {
				return sum == Int64(1)
			}
			target[index] %= sum
			sum += target[index]
			index = maxElementIndex(target)
		}
		return sum == target.count
	}
	
	private func maxElementIndex(_ arr: [Int64]) -> Int {
		var maxIndex = 0
		for i in 1..<arr.count {
			maxIndex = arr[maxIndex] < arr[i] ? i : maxIndex
		}
		return maxIndex
	}
}
