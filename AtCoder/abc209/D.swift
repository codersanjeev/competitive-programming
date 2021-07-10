private func readLn() -> String {
	return readLine() ?? ""
}

private func readLns() -> [String] {
	return readLn().split(separator: " ").map{ String($0) }
}

private func readInts() -> [Int] {
	return readLns().compactMap{ Int($0) }
}

let MAXN = 100005
let LOG = 20
var adj = [[Int]](repeating: [Int](), count: MAXN)
var depth = [Int](repeating: 0, count: MAXN)
var up = [[Int]](repeating: [Int](repeating: 0, count: LOG), count: MAXN)

private func dfs(_ u: Int, _ par: Int) {
	for v in adj[u] {
		if v == par { continue }
		depth[v] = depth[u] + 1
		up[v][0] = u
		for i in 1 ..< LOG {
			up[v][1] = up[up[v][i - 1]][i - 1]
		}
		dfs(v, u)
	}
}

private func lca(_ a: Int, _ b: Int) -> Int {
	var (u, v) = (a, b)
	if depth[u] < depth[v] {
		swap(&u, &v)
	}
	let k = depth[u] - depth[v]
	for i in stride(from: LOG - 1, to: -1, by: -1) {
		if (k & (1 << i)) != 0 {
			u = up[u][i]
		}
	}
	if u == v { return u }
	for i in stride(from: LOG - 1, to: -1, by: -1) {
		if up[u][i] != up[v][i] {
			u = up[u][i]
			v = up[v][i]
		}
	}
	return up[u][0]
}

let nq = readInts()
for _ in 1 ..< nq[0] {
	let uv = readInts()
	adj[uv[0]].append(uv[1])
	adj[uv[1]].append(uv[0])
}
dfs(1, 1)
for _ in 1 ... nq[1] {
	let uv = readInts()
	let w = lca(uv[0], uv[1])
	if (depth[uv[0]] + depth[uv[1]] - 2 * depth[w]) % 2 == 1 {
		print("Road")
	} else {
		print("Town")
	}
}