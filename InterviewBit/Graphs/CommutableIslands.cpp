int find(vector<int> &parent, int i) {
	if (parent[i] == -1) {
		return i;
	}
	return find(parent, parent[i]);
}

void Union(vector<int> &parent, int x, int y) {
	int xp = find(parent, x);
	int yp = find(parent, y);
	parent[xp] = yp;
}

int Solution::solve(int A, vector<vector<int>> &B) {
	sort(B.begin(), B.end(), [](const vector<int> &a, const vector<int> &b) {
		return a[2] < b[2];
	});
	vector<int> parent(A, -1);
	int ans = 0;
	for (int i = 0; i < B.size(); i++) {
		int up = find(parent, B[i][0] - 1);
		int vp = find(parent, B[i][1] - 1);
		if (up != vp) {
			Union(parent, up, vp);
			ans += B[i][2];
		}
	}
	return ans;
}