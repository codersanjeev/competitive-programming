class Solution {
    func sortArrayByParityII(_ A: [Int]) -> [Int] {
        var ans = [Int](repeating: 0, count: A.count)
        var i = 0, j = 1
        A.forEach { ele in 
        	if (ele % 2 == 0) {
        		ans[i] = ele
        		i += 2
    		} else {
    			ans[j] = ele
    			j += 2
    		}
        }
        return ans
    }
}