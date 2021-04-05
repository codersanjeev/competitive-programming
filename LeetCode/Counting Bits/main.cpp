class Solution {
  public:
	vector<int> countBits(int num) {
		vector<int> ans(num + 1);
		ans[0] = 0;
		for (int i = 0; i <= num; i++) {
			if ((i * 2) <= num) {
				ans[i * 2] = ans[i];
			}
			if ((i * 2) + 1 <= num) {
				ans[(i * 2) + 1] = ans[i] + 1;
			}
		}
		return ans;
	}
};