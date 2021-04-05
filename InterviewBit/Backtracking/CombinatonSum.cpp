void f(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &combination, int begin) {
	if (!target) {
		if (find(ans.begin(), ans.end(), combination) == ans.end()) {
			ans.push_back(combination);
		}
		return;
	}
	for (int i = begin; i != candidates.size() && target >= candidates[i]; i++) {
		combination.push_back(candidates[i]);
		f(candidates, target - candidates[i], ans, combination, i);
		combination.pop_back();
	}
}

vector<vector<int>> Solution::combinationSum(vector<int> &candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> ans;
	vector<int> combination;
	f(candidates, target, ans, combination, 0);
	return ans;
}
