class Solution {
    fun evalRPN(tokens: Array<String>): Int {
        val st = Stack<Int>()
        tokens.forEach {
            when (it) {
                "+", "-", "*", "/" -> {
                    val x = st.pop()
                    val y = st.pop()
                    when (it) {
                        "+" -> st.push(y + x)
                        "-" -> st.push(y - x)
                        "*" -> st.push(y * x)
                        "/" -> st.push(y / x)
                    }
                }
                else -> st.push(it.toInt())
            }
        }
        return st.peek()
    }
}