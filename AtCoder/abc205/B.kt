fun main() {
    val n = readLine()!!.toInt()
    val arr = readLine()!!.split(" ")
                .map { it.toInt() }
    when (arr.toHashSet().size) {
        n -> print("Yes")
        else -> print("No")
    }
}