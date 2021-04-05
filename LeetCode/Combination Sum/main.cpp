class Solution {
  public:
	vector<vector<int>> ans;
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		vector<int> temp;
		solve(candidates, temp, target, 0);
		return ans;
	}

  private:
	void solve(const vector<int> &candidates, vector<int> &temp, int remaining, int index) {
		if (remaining < 0) {
			return;
		}
		if (remaining == 0) {
			ans.push_back(temp);
			return;
		}
		for (int i = index; i < candidates.size(); i++) {
			temp.push_back(candidates[i]);
			solve(candidates, temp, remaining - candidates[i], i);
			temp.pop_back();
		}
	}
};