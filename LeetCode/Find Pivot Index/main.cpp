auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

class Solution {
  public:
	int pivotIndex(vector<int>& nums) {
		vector<int> pre = nums, pos = nums;
		int n = nums.size();
		for (int i = 1; i < n; i++) {
			pre[i] += pre[i - 1];
		}
		for (int i = n - 2; i >= 0; i--) {
			pos[i] += pos[i + 1];
		}
		for (int i = 0; i < n; i++) {
			if (pre[i] == pos[i]) {
				return i;
			}
		}
		return -1;
	}
};