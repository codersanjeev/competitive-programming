var arr = readLine()?.split(separator: " ").map({ Int($0) ?? 0 }) ?? []
arr.sort()
if arr[1] - arr[0] == arr[2] - arr[1] {
	print("Yes")
} else {
	print("No")
}