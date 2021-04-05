class Solution {
  public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ans;
		vector<int> curr;
		combinationSum3Util(ans, curr, k, 1, n);
		return ans;
	}

	void combinationSum3Util(vector<vector<int>> &ans, vector<int> &curr, int k, int s, int n) {
		if (n < 0 || curr.size() > k) {
			return;
		}
		if (n == 0 && curr.size() == k) {
			ans.push_back(curr);
			return;
		}
		for (int i = s; i <= 9; i++) {
			curr.push_back(i);
			combinationSum3Util(ans, curr, k, i + 1, n - i);
			curr.pop_back();
		}
	}
};