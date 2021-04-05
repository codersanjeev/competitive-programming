auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

class Solution {
  public:
	int dominantIndex(vector<int>& nums) {
		int n = nums.size(), mx = *max_element(nums.begin(), nums.end()), ans = -1;
		for (int i = 0; i < n; i++) {
			if (nums[i] == mx) {
				ans = i;
			} else if (2 * nums[i] > mx) {
				ans = -1;
				break;
			}
		}
		return ans;
	}
};