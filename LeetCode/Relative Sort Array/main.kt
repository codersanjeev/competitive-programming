class Solution {
    fun relativeSortArray(arr1: IntArray, arr2: IntArray): IntArray {
        var freq = IntArray(1001) { 0 }
        arr1.forEach { ele ->
        	freq[ele]++
        }
        var n = arr1.count(); var k = 0
        var ans = IntArray(n)
        arr2.forEach { ele ->
        	while (freq[ele] > 0) {
        		ans[k++] = ele
        		freq[ele]--
        	}
        }
        for (i in 0 until 1001) {
        	while (freq[i] > 0) {
        		ans[k++] = i
        		freq[i]--
        	}
        }
        return ans
    }
}