import kotlin.math.max

private fun readLn() = readLine() ?: ""
private fun readLns() = readLn().split(" ")
private fun readInts() = readLns().map { it.toInt() }

fun main() {
    val NK = readInts()
    val c = readInts()
    val window = mutableMapOf<Int, Int>()
    for (i in 0 until NK[1]) {
        window.incrementKey(c[i])
    }
    var ans = window.size
    for (i in NK[1] until NK[0]) {
        window[c[i - NK[1]]]?.let {
            window[c[i - NK[1]]] = it - 1
        }
        window.incrementKey(c[i])
        window[c[i - NK[1]]]?.let {
            if (it == 0) window.remove(c[i - NK[1]])
        }
        ans = max(ans, window.size)
    }
    print(ans)
}

fun MutableMap<Int, Int>.incrementKey(key: Int) {
    this[key]?.let {
        this[key] = it + 1
    } ?: run {
        this[key] = 1
    }
}