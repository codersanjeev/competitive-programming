class Solution {
    fun sortArrayByParityII(A: IntArray): IntArray {
		var ans = IntArray(A.count())
		var (i, j) = listOf(0, 1)
		A.forEach { ele ->
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