import kotlin.math.max
import kotlin.math.min

private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readLongs() = readLns().map { it.toLong() }

fun main() {
    val n = readInt()
    val arr = mutableListOf<Pair<Long, Long>>()
    for (i in 0 until n) {
        val nums = readLongs().toMutableList()
        nums[1] *= 2L
        nums[2] *= 2L
        when (nums[0]) {
            1L -> arr.add(Pair(nums[1], nums[2]))
            2L -> arr.add(Pair(nums[1], nums[2] - 1))
            3L -> arr.add(Pair(nums[1] + 1, nums[2]))
            4L -> arr.add(Pair(nums[1] + 1, nums[2] - 1))
        }
    }
    var ans = 0
    for (i in 0 until n) {
        for (j in i + 1 until n) {
            if (max(arr[i].first, arr[j].first) <=
                min(arr[i].second, arr[j].second)) {
                ++ans
            }
        }
    }
    print(ans)
}