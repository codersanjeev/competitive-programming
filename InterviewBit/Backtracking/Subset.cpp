void findAnswer(vector<int> &arr, int i, vector<int> &curr, vector<vector<int>> &ans) {
	ans.push_back(curr);
	int n = arr.size();
	for (int j = i; j < n; j++) {
		curr.push_back(arr[j]);
		findAnswer(arr, j + 1, curr, ans);
		curr.pop_back();
	}
	return;
}

vector<vector<int>> Solution::subsets(vector<int> &arr) {
	int n = arr.size();
	vector<int> curr;
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	curr.clear();
	ans.clear();
	findAnswer(arr, 0, curr, ans);
	return ans;
}
