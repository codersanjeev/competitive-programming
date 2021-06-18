extension String {
	var intValue: Int {
		return Int(self) ?? 0
	}
}

private func readLn() -> String { return readLine() ?? "" }
private func readLns() -> [String] {
	return readLn().split(separator: " ").compactMap({ String($0) })
}
private func readInt() -> Int {
	return readLn().intValue
}
private func readInts() -> [Int] {
	return readLns().map({ $0.intValue })
}

private func dfs(_ adj: [[Int]], _ visited: inout [Bool], _ u: Int) -> Int {
	if visited[u] { return 0 }
	visited[u] = true
	var ans = 1
	for v in adj[u] {
		ans += dfs(adj, &visited, v)
	}
	return ans
}

let nm = readInts()
var adj = [[Int]](repeating: [Int](), count: nm[0])
for _ in 0 ..< nm[1] {
	let uv = readInts()
	adj[uv[0] - 1].append(uv[1] - 1)
}
var ans = 0
for u in 0 ..< nm[0] {
	var visited = [Bool](repeating: false, count: nm[0])
	ans += dfs(adj, &visited, u)
}
print(ans)
