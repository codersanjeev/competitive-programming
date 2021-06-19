private fun readLn() = readLine()!!
private fun readDouble() = readLn().toDouble()

fun main() {
    val n = readDouble()
    var ans = "so-so"
    if ((n * 1.08).toInt() < 206) {
        ans = "Yay!"
    } else if ((n * 1.08).toInt() > 206) {
        ans = ":("
    }
    print(ans)
}