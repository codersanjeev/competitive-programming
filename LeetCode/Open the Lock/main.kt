class Solution {
    fun openLock(deadends: Array<String>, target: String): Int {
    val avoid = deadends.toHashSet()
    val seen = HashSet<String>()
    val q = ArrayDeque<String>()
    var steps = 0
    
    q.offer("0000")
    seen.add("0000")

    fun queueIfPossible(ca: CharArray) {
        val s = String(ca)
        if (!seen.contains(s)) {
            q.offer(s)
            seen.add(s)
        }
    }

    while (!q.isEmpty()) {
        val size = q.size
        
        for (dummy in 0..size - 1) {
            val w = q.poll()

            if (avoid.contains(w)) continue

            if (w == target) return steps
            
            for (i in 0..w.length - 1) {
                val ca = w.toCharArray()
                // +
                ca[i] = if (w[i] == '9') '0' else (w[i] + 1).toChar()
                queueIfPossible(ca)
                // -
                ca[i] = if (w[i] == '0') '9' else (w[i] - 1).toChar()
                queueIfPossible(ca)                    
            }
        }

        steps++
    }
    
    return -1
}
}