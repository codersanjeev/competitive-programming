
class OrderedStream {

    fileprivate var n: Int = 0
    fileprivate var arr = [String]()
    fileprivate var idx: Int = 0
    
    init(_ n: Int) {
        self.n = n
        for i in 0..<n {
            self.arr.append("")
        }
    }
    
    func insert(_ id: Int, _ value: String) -> [String] {
        arr[id - 1] = value
        var ans = [String]()
        while (idx < n) {
            if (arr[idx] == "") {
                break
            }
            ans.append(arr[idx])
            idx += 1
        }
        return ans
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * let obj = OrderedStream(n)
 * let ret_1: [String] = obj.insert(id, value)
 */