private fun readLn() = readLine()!!

fun main(args: Array<String>) {
    val s = readLn()
    s.reversed().forEach {
        when (it) {
            '6' -> print(9)
            '9' -> print(6)
            else -> print(it)
        }
    }
}