class FindSumPairs(nums1: IntArray, nums2: IntArray) {

    private var X: IntArray = nums1
    private var Y: IntArray = nums2
    private var mp = hashMapOf<Int, Int>()

    init {
        Y.forEach {
            mp[it] = mp.getOrDefault(it, 0) + 1
        }
    }

    fun add(index: Int, delta: Int) {
        val oldValue = Y[index]
        Y[index] += delta
        val newValue = Y[index]
        mp[oldValue] = mp.getOrDefault(oldValue, 0) - 1
        mp[newValue] = mp.getOrDefault(newValue, 0) + 1
    }

    fun count(target: Int): Int {
        var answer = 0
        X.forEach {
            answer += mp.getOrDefault(target - it, 0)
        }
        return answer
    }
}