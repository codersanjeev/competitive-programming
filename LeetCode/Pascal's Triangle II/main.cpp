auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> getRow(int n) {
    	if (n == 0) return {1};
    	vector<int> ans(n + 1);
    	vector<vector<int>> dp(34, vector<int>(34, -1));
    	for (int r = 0; r < n + 1; r++) {
    		ans[r] = nCr(n, r, dp);
    	}
    	return ans;
	}
private:
	int nCr(int n, int r, vector<vector<int>> &dp) {
		if (r == 0 || r == n) return 1;
		r = min(r, n - r);
		if (dp[n][r] != -1) return dp[n][r];
		return dp[n][r] = nCr(n - 1, r, dp) + nCr(n - 1, r - 1, dp);
	}
};