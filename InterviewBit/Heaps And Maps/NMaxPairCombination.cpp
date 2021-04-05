vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
	int n = A.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	priority_queue<pair<int, pair<int, int>>> arr;
	arr.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
	set<pair<int, int>> st;
	st.insert({n - 1, n - 1});
	vector<int> ans;
	while (n--) {
		auto curr = arr.top();
		arr.pop();
		ans.push_back(curr.first);
		int i = curr.second.first;
		int j = curr.second.second;
		int next = A[i - 1] + B[j];
		if (st.find({i - 1, j}) == st.end()) {
			arr.push({next, {i - 1, j}});
			st.insert({i - 1, j});
		}
		next = A[i] + B[j - 1];
		if (st.find({i, j - 1}) == st.end()) {
			arr.push({next, {i, j - 1}});
			st.insert({i, j - 1});
		}
	}
	return ans;
}
