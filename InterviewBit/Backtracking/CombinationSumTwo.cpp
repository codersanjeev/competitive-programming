void f(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &arr, int index, int sum, int target) {
	if (sum == target) {
		ans.push_back(arr);
	}
	if (index >= candidates.size() || sum > target) {
		return;
	}
	for (int i = index; i < candidates.size(); i++) {
		arr.push_back(candidates[i]);
		f(candidates, ans, arr, i + 1, sum + candidates[i], target);
		while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
			i++;
		}
		arr.pop_back();
	}
}

vector<vector<int>> Solution::combinationSum(vector<int> &candidates, int target) {
	vector<vector<int>> ans;
	sort(candidates.begin(), candidates.end());
	vector<int> arr;
	f(candidates, ans, arr, 0, 0, target);
	return ans;
}
