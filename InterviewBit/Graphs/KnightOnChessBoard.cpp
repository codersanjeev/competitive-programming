int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1};

int Solution::knight(int m, int n, int si, int sj, int fi, int fj) {
	if (si == fi && sj == fj) {
		return 0;
	}
	queue<pair<pair<int, int>, int>> q;
	set<pair<int, int>> visited;
	q.push({{si, sj}, 0});
	visited.insert({si, sj});
	while (!q.empty()) {
		auto curr = q.front();
		q.pop();
		if (curr.first.first == fi && curr.first.second == fj) {
			return curr.second;
		}
		for (int i = 0; i < 8; i++) {
			int nx = curr.first.first + dx[i];
			int ny = curr.first.second + dy[i];
			if (visited.find({nx, ny}) == visited.end() && nx >= 1 && ny >= 1 && nx <= m && ny <= n) {
				visited.insert({nx, ny});
				q.push({{nx, ny}, curr.second + 1});
			}
		}
	}
	return -1;
}
