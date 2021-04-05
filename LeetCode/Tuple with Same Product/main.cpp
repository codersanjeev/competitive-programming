#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

class Solution {
  public:
	int tupleSameProduct(vector<int> &nums) {
		int n = nums.size();
		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				mp[nums[i] * nums[j]]++;
			}
		}
		int ans = 0;
		for (const auto &ele : mp) {
			int cnt = ele.second;
			ans += (cnt * (cnt - 1) * 4);
		}
		return ans;
	}
};