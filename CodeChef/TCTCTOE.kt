private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

private var states = hashMapOf<String, Int>()

private fun isWonOrDrawn(state: Array<Array<Char>>): Boolean {
    var emptyCount = 0
    for (i in 0 until 3) {
        if (state[i][0] == state[i][1] && state[i][1] == state[i][2] && (state[i][0] == 'O' || state[i][0] == 'X')) {
            return true
        }
        if (state[0][i] == state[1][i] && state[1][i] == state[2][i] && (state[0][i] == 'O' || state[0][i] == 'X')) {
            return true
        }
    }
    if (state[0][0] == state[1][1] && state[1][1] == state[2][2] &&
        (state[0][0] == 'O' || state[0][0] == 'X')
    ) {
        return true
    }
    if (state[0][2] == state[1][1] && state[1][1] == state[2][0] &&
        (state[0][2] == 'O' || state[0][2] == 'X')
    ) {
        return true
    }
    state.forEach {
        it.forEach { ch ->
            if (ch == '_') emptyCount++
        }
    }
    return emptyCount == 0;
}

private fun precomputation(board: Array<Array<Char>>, turn: Boolean) {
    if (isWonOrDrawn(board)) {
        states[board.serialize()] = 1
        return
    }
    states[board.serialize()] = 2
    for (i in 0 until 3) {
        for (j in 0 until 3) {
            if (board[i][j] == '_') {
                board[i][j] = if (turn) 'X' else 'O'
                precomputation(board, !turn)
                board[i][j] = '_'
            }
        }
    }
}

fun main(args: Array<String>) {
    val board = Array(3) { Array<Char>(3) { '_' } }
    precomputation(board, true)
    val T = readInt()
    for (i in 0 until T) {
        for (j in 0 until 3) {
            val s = readLn()
            for (k in 0 until 3) board[j][k] = s[k]
        }
        states[board.serialize()]?.let {
            println(it)
        } ?: run {
            println(3)
        }
    }
}

fun Array<Array<Char>>.serialize(): String {
    var ans = ""
    this.forEach {
        it.forEach { ch ->
            ans += ch
        }
        ans += '$'
    }
    return ans
}
