fun main() {
    val n = readLine()!!.toInt()
    val arr = mutableListOf<Pair<Int, String>>()
    for (i in 0 until n) {
        val (name, height) = readLine()!!.split(" ")
        arr.add(Pair(height.toInt(), name))
    }
    arr.sortBy { it.first }
    print(arr[n - 2].second)
}