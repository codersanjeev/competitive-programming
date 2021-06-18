class Solution {
    fun ambiguousCoordinates(S: String): List<String> {
        var s = S.substring(1)
        s = s.substring(0, s.length - 1)
        val answer = ArrayList<String>()
        for (i in 1 until s.length) {
            val left = generateNumbers(s.substring(0, i))
            val right = generateNumbers(s.substring(i))
            for (l in left) {
                for (r in right) {
                    answer.add("($l, $r)")
                }
            }
        }
        return answer
    }

    private fun generateNumbers(s: String): List<String> {
        val answer = ArrayList<String>()
        if (s.first() == '0' && s.last() == '0') {
            if (s.length == 1) answer.add(s)
            return answer
        }
        when {
            s.first() == '0' -> {
                answer.add("0." + s.substring(1))
            }
            s.last() == '0' -> {
                answer.add(s)
            }
            else -> {
                answer.add(s)
                for (i in 1 until s.length) {
                    val num = s.substring(0, i) + "." + s.substring(i)
                    answer.add(num)
                }
            }
        }
        return answer
    }
}