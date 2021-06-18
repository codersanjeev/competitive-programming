class Solution {
    fun mergeTriplets(triplets: Array<IntArray>, target: IntArray): Boolean {
        val start = IntArray(3)
        for (triplet in triplets) {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                for (i in 0 until 3) start[i] = start[i].coerceAtLeast(triplet[i])
            }
        }
        return start.contentEquals(target)
    }
}