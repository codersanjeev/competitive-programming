class DSU {
	private var parent: [Int]
	private var rank: [Int]
	
	init(_ n: Int) {
		parent = [Int](repeating: -1, count: n)
		rank = [Int](repeating: 1, count: n)
	}
	
	private func find(_ u: Int) -> Int {
		if parent[u] == -1 {
			return u
		} else {
			parent[u] = find(parent[u])
			return parent[u]
		}
	}
	
	func merge(_ u: Int, _ v: Int) -> Bool {
		let a = find(u)
		let b = find(v)
		if a != b {
			if rank[a] < rank[b] {
				parent[a] = b
				rank[b] += rank[a]
			} else {
				parent[b] = a
				rank[a] += rank[b]
			}
			return true
		}
		return false
	}
}

class Solution {
	func findRedundantConnection(_ edges: [[Int]]) -> [Int] {
		let dsu = DSU(edges.count)
		for edge in edges {
			if dsu.merge(edge[0] - 1, edge[1] - 1) == false {
				return edge
			}
		}
		return []
	}
}