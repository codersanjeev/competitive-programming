const int N = 5e5;
vector<int> tree(N, 0);

int buildTree(int l, int r, int i) {
	if (l > r) { return 0; }
	if (l == r) {
		tree[i] = 1;
		return 1;
	}
	int mid = l + (r - l) / 2;
	int L = buildTree(l, mid, 2 * i + 1);
	int R = buildTree(mid + 1, r, 2 * i + 2);
	tree[i] = L + R;
	return tree[i];
}

int updateTree(int i, int val, int l, int r, int index) {
	if (l > r) { return 0; }
	if (l == r) {
		tree[index] = val;
		return val;
	}
	int mid = l + (r - l) / 2;
	int L = 0, R = 0;
	if (i <= mid) { L = updateTree(i, val, l, mid, 2 * index + 1); }
	else { R = updateTree(i, val, mid + 1, r, 2 * index + 2); }
	return tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
}

int queryTree(int spaces, int l, int r, int i) {
	if (l > r) { return -1; }
	int leftSpaces = tree[2 * i + 1];
	int rightSpaces = tree[2 * i + 2];
	if (l == r) { return l; }
	return leftSpaces >= spaces ? queryTree(spaces, l, (l + r) / 2, 2 * i + 1) : queryTree(spaces - leftSpaces, (l + r) / 2 + 1, r, 2 * i + 2);
}

vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
	int n = heights.size();
	buildTree(0, n - 1, 0);
	vector<pair<int, int>> v;
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
		v.push_back({heights[i], infronts[i]});
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int index = queryTree(v[i].second + 1, 0, n - 1, 0);
		ans[index] = v[i].first;
		updateTree(index, 0, 0, n - 1, 0);
	}
	return ans;
}