class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
		int n = code.size();
		vector<int> ans(n, 0);
		if (k > 0) {
			// ans[i] = sum of next k numbers
			for (int i = 0; i < n; i++) {
				int curr = 0;
				for (int j = i + 1; j < i + 1 + k; j++) {
					curr += code[j % n];
				}
				ans[i] = curr;
			}
		} else {
			k *= -1;
			// ans[i] = sum of previous k numbers
			for (int i = 0; i < n; i++) {
				int curr = 0;
				for (int j = i - 1; j > i - 1 - k; j--) {
					curr += code[(j + n) % n];
				}
				ans[i] = curr;
			}
		}
		return ans;
    }
};