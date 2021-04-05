import java.util.*

@JvmField
val INPUT = System.`in`

@JvmField
val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!

@JvmField
var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}

fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

fun main(args: Array<String>) {
    val n = readInt()
    val s = read()
    var ans = 0
    var index = 0
    var cnt = 0
    while (index < n) {
        if (s[index] == 'x') {
            cnt++
        } else {
            if (cnt >= 3) {
                ans += (cnt - 2)
            }
            cnt = 0
        }
        index++
    }
    if (cnt >= 3) {
        ans += (cnt - 2)
    }
    println(ans)
}