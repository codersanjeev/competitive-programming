class Solution {
  public:
	int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps) {
		// allowedSwaps in source b/w ai, bi
		// find min hamming distance b/w source and target
		int n = source.size();
		vector<int> parent(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		for (const auto &ele : allowedSwaps) {
			unionTree(parent, ele[0], ele[1]);
		}
		map<int, multiset<int>> mp;
		for (int i = 0; i < n; i++) {
			int u = findRoot(parent, i);
			mp[u].insert(source[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int u = findRoot(parent, i);
			auto it = mp[u].find(target[i]);
			if (it != mp[u].end()) {
				mp[u].erase(it);
			} else {
				ans++;
			}
		}
		return ans;
	}
  private:
	void unionTree(vector<int> &parent, int u, int v) {
		int pu = findRoot(parent, u);
		int pv = findRoot(parent, v);
		if (pu != pv) {
			parent[pu] = pv;
		}
	}

	int findRoot(vector<int> &parent, int u) {
		while (u != parent[u]) {
			parent[u] = parent[parent[u]];
			u = parent[u];
		}
		return u;
	}

};