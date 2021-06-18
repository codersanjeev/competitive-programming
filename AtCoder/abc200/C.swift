var s = readLine() ?? ""
let n = Int64(s) ?? Int64(0)
let arr = readLine()?.split(separator: " ").map({ Int64($0) ?? Int64(0) }) ?? []

var mp = [Int64:Int64]()

arr.forEach { ele in
	let key = (ele + 200) % 200
	let value = mp[key] ?? Int64(0)
	mp[key] = value + 1
}

var ans = Int64(0)

mp.forEach { (key, value) in
	ans += (value * (value - 1)) / 2
}

print(ans)
