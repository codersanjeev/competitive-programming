class Solution {
    fun isPossible(target: IntArray): Boolean {
        var sum = target.sum().toLong()
        var index = target.maxElementIndex()
        while (sum > 1L && target[index] > sum / 2) {
            sum -= target[index]
            if (sum <= 1) {
                return sum == 1L
            }
            target[index] %= sum.toInt()
            sum += target[index]
            index = target.maxElementIndex()
        }
        return sum == target.size.toLong()
    }
}

fun IntArray.maxElementIndex(): Int {
    var maxIndex = 0
    for (i in 1 until this.count()) {
        maxIndex = if (this[maxIndex] < this[i]) i else maxIndex
    }
    return maxIndex
}