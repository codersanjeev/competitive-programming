class Solution {
  public:
	vector<int> constructDistancedSequence(int n) {
		// for each i in [2, n], distance b/w two i's
		// is i
		// total elements = 2 * (n - 1) + 1 = 2.n - 1
		vector<int> ans((2 * n) - 1, 0);
		vector<bool> used(n + 1, false);
		dfs(ans, used, 0);
		return ans;
	}
  private:
	bool dfs(vector<int> &ans, vector<bool> &used, int idx) {
		// reached end of the array
		if (idx == ans.size()) {
			return true;
		}
		// already placed arr[idx], then move to next index
		if (ans[idx] != 0) {
			return dfs(ans, used, idx + 1);
		}
		for (int i = used.size() - 1; i >= 1; i--) {
			// i is not used and i + idx space is empty,
			// we can try using, idx and i + idx for placing i
			if (!used[i] && (i == 1 || (i + idx) < ans.size() && ans[i + idx] == 0)) {
				ans[idx] = i;
				if (i != 1) {
					ans[i + idx] = i;
				}
				used[i] = true;
				if (dfs(ans, used, idx + 1)) {
					return true;
				}
				// backtrack, undo the changes
				ans[idx] = 0;
				if (i != 1) {
					ans[i + idx] = 0;
				}
				used[i] = false;
			}
		}
		// unable to find a solution
		return false;
	}
};