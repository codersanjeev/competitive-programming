vector<int> ans;

void bfs(int n, int m, int i) {
	queue<int> q;
	q.push(i);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		if (curr >= n && curr <= m) {
			ans.push_back(curr);
		}
		if (i == 0 || curr > m) {
			continue;
		}
		int last = curr % 10;
		int x = curr * 10 + (last - 1);
		int y = curr * 10 + (last + 1);
		if (last == 0) {
			q.push(y);
		} else if (last == 9) {
			q.push(x);
		} else {
			q.push(x);
			q.push(y);
		}
	}
}

vector<int> Solution::stepnum(int A, int B) {
	if (A > B) {
		return vector<int>(0);
	}
	ans.clear();
	for (int i = 0; i <= 9; i++) {
		bfs(A, B, i);
	}
	sort(ans.begin(), ans.end());
	return ans;
}
