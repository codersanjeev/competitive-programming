private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val NAXY = readInts()
    if (NAXY[0] <= NAXY[1]) {
        print(NAXY[0] * NAXY[2])
    } else {
        print(NAXY[1] * NAXY[2] + (NAXY[0] - NAXY[1]) * NAXY[3])
    }
}