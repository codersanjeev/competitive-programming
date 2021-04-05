class Solution {
    fun canFormArray(arr: IntArray, pieces: Array<IntArray>): Boolean {
        var mp: MutableMap<Int, IntArray> = mutableMapOf<Int, IntArray>()
        pieces.forEach { piece ->
            mp[piece[0]] = piece
        }
        var idx = 0
        val n = arr.count()
        while (idx < n) {
            if (mp.containsKey(arr[idx]) == false) {
                return false
            }
            mp[arr[idx]]?.forEach { ele -> 
                if (ele != arr[idx]) {
                    return false
                }
                idx++
            }
        }
        return idx == n
    }
}