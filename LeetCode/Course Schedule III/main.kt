import java.util.*
import kotlin.Comparator

class Solution {
    fun scheduleCourse(courses: Array<IntArray>): Int {
        courses.sortBy { it[1] }
        var currentTime = 0
        val pq = PriorityQueue(ReverseComparator)
        courses.forEach {
            currentTime += it[0]
            pq.add(it[0])
            if (currentTime > it[1]) {
                currentTime -= pq.poll()
            }
        }
        return pq.size
    }

    class ReverseComparator {
        companion object : Comparator<Int> {
            override fun compare(x: Int, y: Int): Int {
                return if (x < y) 1 else -1
            }
        }
    }

}