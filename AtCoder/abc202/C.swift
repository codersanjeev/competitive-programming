let n = Int(readLine()!)!
let a = readLine()!.split(separator: " ").map({ Int($0)! })
let b = readLine()!.split(separator: " ").map({ Int($0)! })
let c = readLine()!.split(separator: " ").map({ Int($0)! })
var mp = [Int:Int]()
a.forEach {
	mp[$0] = (mp[$0] ?? 0) + 1
}
var ans = 0
for i in 0..<n {
	let curr = b[c[i] - 1]
	ans += mp[curr] ?? 0
}
print(ans)
