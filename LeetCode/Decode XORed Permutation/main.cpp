class Solution {
  public:
	vector<int> decode(vector<int> &encoded) {
		int n = encoded.size(), a0 = 0;
		for (int i = 1; i <= n + 1; i++) {
			a0 ^= i;
		}
		for (int i = 1; i < n; i += 2) {
			a0 ^= encoded[i];
		}
		vector<int> ans(n + 1);
		ans[0] = a0;
		for (int i = 1; i <= n; i++) {
			ans[i] = ans[i - 1] ^ encoded[i - 1];
		}
		return ans;
	}
};