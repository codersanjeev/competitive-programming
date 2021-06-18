struct Mountain {
	let name: String
	let height: Int
}

var arr = [Mountain]()

let s = readLine() ?? ""
let n = s.toInteger()
for _ in 1...n {
	let curr = readLine()?.split(separator: " ") ?? []
	arr.append(Mountain(name: String(curr[0]), height: String(curr[1]).toInteger()))
}
arr.sort() {
	$0.height > $1.height
}
print(arr[1].name)


extension String {
	func toInteger() -> Int {
		return Int(self) ?? 0
	}
}
