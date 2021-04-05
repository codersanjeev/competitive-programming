void f(vector<int> &arr, int begin, vector<vector<int>> &ans) {
	if (begin >= arr.size()) {
		ans.push_back(arr);
		return;
	}
	for (int i = begin; i < arr.size(); i++) {
		swap(arr[begin], arr[i]);
		f(arr, begin + 1, ans);
		swap(arr[begin], arr[i]);
	}
}

vector<vector<int>> Solution::permute(vector<int> &arr) {
	vector<vector<int>> ans;
	f(arr, 0, ans);
	return ans;
}
