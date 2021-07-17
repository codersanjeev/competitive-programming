class Solution {
    fun threeEqualParts(arr: IntArray): IntArray {
        var ones = arr.count { it == 1 }
        if (ones % 3 != 0) return intArrayOf(-1, -1)
        if (ones == 0) return intArrayOf(0, arr.size - 1)
        ones /= 3
        var (curr, x, y, z) = listOf(0, 0, 0, 0)
        for (i in arr.indices) {
            if (arr[i] == 1) {
                if (curr % ones == 0) {
                    when (curr / ones) {
                        0 -> x = i
                        1 -> y = i
                        2 -> z = i
                    }
                }
                ++curr
            }
        }
        while (z != arr.size) {
            if (arr[x] != arr[y] || arr[y] != arr[z]) {
                return intArrayOf(-1, -1)
            }
            ++x; ++y; ++z
        }
        return intArrayOf(x - 1, y)
    }
}