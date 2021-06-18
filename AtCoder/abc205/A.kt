fun main() {
    val (a, b) = readLine()!!.split(" ")
                    .map { it.toDouble() }
    print((a * b) / 100)
}