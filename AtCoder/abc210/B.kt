private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInt() = readLn().toInt()

fun main() {
    val N = readInt()
    val S = readLn()
    var first = true
    for (i in S.indices) {
        if (S[i] == '1') {
            first = i % 2 == 0
            break
        }
    }
    when (first) {
        true -> print("Takahashi")
        false -> print("Aoki")
    }
}