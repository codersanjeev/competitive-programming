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

vector<vector<int>> Solution::subsetsWithDup(vector<int> &arr) {
	int n = arr.size();
	vector<int> curr;
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	curr.clear();
	ans.clear();
	findAnswer(arr, 0, curr, ans);
	set<vector<int>> st;
	for (auto ele : ans) {
		st.insert(ele);
	}
	ans.clear();
	for (auto ele : st) {
		ans.push_back(ele);
	}
	return ans;
}
