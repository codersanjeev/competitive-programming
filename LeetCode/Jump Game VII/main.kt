class Solution {
    fun canReach(s: String, minJump: Int, maxJump: Int): Boolean {
        val reachable: Queue<Int> = LinkedList()
        reachable.add(0)
        for (i in 1 until s.length) {
            if (s[i] == '0') {
                while (reachable.isNotEmpty() && (reachable.peek() ?: 0) < i - maxJump) {
                    reachable.poll()
                }
                if (reachable.isNotEmpty() && (reachable.peek() ?: 0) <= i - minJump) {
                    reachable.add(i)
                }
            }
        }
        return reachable.isNotEmpty() && reachable.last() == s.length - 1
    }
}