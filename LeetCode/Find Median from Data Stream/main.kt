class MedianFinder() {
    private val left = PriorityQueue<Int>()
    private val right = PriorityQueue<Int>(Collections.reverseOrder())

    fun addNum(num: Int) {
        left.add(num)
        left.poll()?.let {
            right.add(it)
        }
        if (left.size < right.size) {
            right.poll()?.let {
                left.add(it)
            }
        }
    }

    fun findMedian(): Double {
        return if (left.size > right.size) {
            left.peek()?.toDouble() ?: 0.0
        } else {
            left.peek()?.toDouble()?.plus(right.peek()?.toDouble() ?: 0.0)?.times(0.5) ?: 0.0
        }
    }
}