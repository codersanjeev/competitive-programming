string Solution::multiple(int n) {
	queue<int> q;
	vector<bool> visited(n + 1, false);
	q.push(1 % n);
	visited[1 % n] = true;
	vector<pair<int, char>> parent(n + 1, { -1, '1'});
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		if (top == 0) {
			string ans = "";
			ans += parent[0].second;
			int i = parent[0].first;
			while (i != -1) {
				ans += parent[i].second;
				i = parent[i].first;
			}
			reverse(ans.begin(), ans.end());
			return ans;
		}
		int x = (top * 10) % n;
		int y = ((top * 10) % n + 1) % n;
		if (!visited[x]) {
			visited[x] = true;
			q.push(x);
			parent[x] = {top, '0'};
		}
		if (!visited[y]) {
			visited[y] = true;
			q.push(y);
			parent[y] = {top, '1'};
		}
	}
}
