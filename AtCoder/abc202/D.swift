var arr = readLine()!.split(separator: " ").map({ Int64($0)! })
let N = arr[0] + arr[1]
var ans = ""

var nCr = [[Int64]](repeating: [Int64](repeating: Int64(0), count: 61), count: 61)

nCr[0][0] = Int64(1)

for i in 1 ... 60 {
	nCr[i][0] = Int64(1)
	nCr[i][i] = Int64(1)
	for j in 1 ..< 60 {
		nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1]
	}
}

for i in Int64(0) ..< N {
	let (i, j) = (Int(arr[0] + arr[1] - 1), Int(arr[1]))
	let cnt = nCr[i][j]
	if cnt >= arr[2] {
		arr[0] -= Int64(1)
		ans += "a"
		
	} else {
		arr[1] -= Int64(1)
		arr[2] -= cnt
		ans += "b"
	}
}

print(ans)
