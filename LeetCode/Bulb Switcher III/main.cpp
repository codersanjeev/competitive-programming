class Solution {
  public:
	int numTimesAllBlue(vector<int>& light) {
		int right = 0, ans = 0, n = light.size();
		for (int i = 0; i < n; i++) {
			right = max(right, light[i]);
			if (right == i + 1) {
				ans++;
			}
		}
		return ans;
	}
};