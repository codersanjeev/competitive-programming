let n = Int(readLine()!) ?? 0
let nums = readLine()!.split(separator: " ")
var st = Set<Int>()
for num in nums {
	st.insert(Int(num) ?? 0)
}
if st.count == n {
	print("Yes")
} else {
	print("No")
}
