vector<vector<int>> Solution::diagonal(vector<vector<int>> &A) {
	vector<vector<int>> ans;
	map<int, vector<int>> mp;
	int n = A.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mp[i + j].push_back(A[i][j]);
		}
	}
	for (auto ele : mp) {
		ans.push_back(ele.second);
	}
	return ans;
}