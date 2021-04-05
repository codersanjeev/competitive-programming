class Solution {
  public:
	int maxEnvelopes(vector<vector<int>> &envelopes) {
		if (envelopes.size() < 2) {
			return envelopes.size();
		}
		sort(envelopes.begin(), envelopes.end(), [](const vector<int> &x, const vector<int> &y) {
			int a = x[0] * x[1];
			int b = y[0] * y[1];
			return a < b;
		});
		int n = envelopes.size();
		vector<int> dp(n, 1);
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
					dp[i] = max(dp[i], 1 + dp[j]);
				}
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};