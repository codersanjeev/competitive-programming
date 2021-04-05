class OrderedStream(n: Int) {

    var arr: MutableList<String> = Collections.nCopies(n, "").toMutableList()
    var idx = 0
    
    fun insert(id: Int, value: String): List<String> {
        var ans: MutableList<String> = emptyList<String>().toMutableList()
        arr[id - 1] = value
        do {
            if (arr[idx] == "") break
            ans.add(arr[idx])
            idx++
        } while (idx < arr.size)
        return ans
    }

}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * var obj = OrderedStream(n)
 * var param_1 = obj.insert(id,value)
 */