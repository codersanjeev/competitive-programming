class Solution {
  public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
		vector<int> adj[N];
		vector<int> count(N, 0), res(N, 0);
		for (const auto &ele : edges) {
			adj[ele[0]].push_back(ele[1]);
			adj[ele[1]].push_back(ele[0]);
		}
		dfs(adj, count, res, 0, -1);
		dfs2(adj, count, res, 0, -1);
		return res;
	}

  private:
	void dfs(vector<int> adj[], vector<int> &count, vector<int> &res, int u, int par) {
		for (const auto &v : adj[u]) {
			if (v != par) {
				dfs(adj, count, res, v, u);
				count[u] += count[v]; // nodes in subtree
				res[u] += count[v] + res[v]; // sum of distance
			}
		}
		count[u]++;
	}

	void dfs2(vector<int> adj[], vector<int> &count, vector<int> &res, int u, int par) {
		for (const auto &v : adj[u]) {
			if (v != par) {
				res[v] = res[u] - count[v] + count.size() - count[v];
				dfs2(adj, count, res, v, u);
			}
		}
	}

};