#define max 100001LL
#define mod 1000000007LL

vector<pair<long long, pair<long long, long long>>> edges;
vector<long long> parent(max);
vector<long long> sz(max);

long long findParent(long long n) {
	while (n != parent[n]) {
		parent[n] = parent[parent[n]];
		n = parent[n];
	}
	return n;
}

void performUnion(long long x, long long y) {
	long long u = findParent(x);
	long long v = findParent(y);
	if (u != v) {
		if (sz[u] < sz[v])
			swap(u, v);
		parent[v] = u;
		sz[u] += sz[v];
	}
}

int Solution::solve(vector<vector<int>> &arr) {
	edges.clear();
	for (long long i = 0LL; i < max; i++) {
		parent[i] = i;
		sz[i] = 1LL;
	}
	for (auto ele : arr) {
		edges.push_back({ele[2], {ele[0], ele[1]}});
	}
	sort(edges.begin(), edges.end());
	long long ans = 0LL;
	for (auto ele : edges) {
		ans = (ans % mod + ele.first * (sz[findParent(ele.second.first)] * sz[findParent(ele.second.second)] % mod) % mod) % mod;
		performUnion(ele.second.first, ele.second.second);
	}
	return ans;
}
