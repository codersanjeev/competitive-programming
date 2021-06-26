private func readLn() -> String {
	return readLine() ?? ""
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readInt() -> Int {
	return Int(readLn()) ?? 0
}

private func readLongs() -> [Int64] {
	return readLns().compactMap{ Int64($0) }
}

let n = readInt()
var arr = [[Int64]]()
for _ in 0 ..< n {
	var nums = readLongs()
	nums[1] *= 2
	nums[2] *= 2
	if nums[0] == 1 {
		arr.append([nums[1], nums[2]])
	} else if nums[0] == 2 {
		arr.append([nums[1], nums[2] - 1])
	} else if nums[0] == 3 {
		arr.append([nums[1] + 1, nums[2]])
	} else {
		arr.append([nums[1] + 1, nums[2] - 1])
	}
}
var ans = 0
for i in 0 ..< n {
	for j in i + 1 ..< n {
		if max(arr[i][0], arr[j][0]) <= 
           min(arr[i][1], arr[j][1]) {
			ans += 1
		}
	}
}
print(ans)