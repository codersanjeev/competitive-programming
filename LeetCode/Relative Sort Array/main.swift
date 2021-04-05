class Solution {
    func relativeSortArray(_ arr1: [Int], _ arr2: [Int]) -> [Int] {
        var freq = Array<Int>(repeating: 0, count: 1001)
        var n = arr1.count, k = 0
        var ans = [Int]()
        arr1.forEach { ele in 
        	freq[ele] += 1
        }
        arr2.forEach { ele in 
        	while (freq[ele] > 0) {
        		ans.append(ele)
        		freq[ele] -= 1
        	}
        }
        for i in 0..<1001 {
        	while (freq[i] > 0) {
        		ans.append(i)
        		freq[i] -= 1
        	}
        }
        return ans
    }
}