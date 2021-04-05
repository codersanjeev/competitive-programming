auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

class Solution {
  public:
	int countPairs(vector<int>& arr) {
		const long long mod = (long long) 1e9 + 7;
		long long ans = 0LL;
		map<long long, long long> mp;
		sort(arr.begin(), arr.end());
		for (const auto &ele : arr) {
			for (long long i = 0LL; i < 31; i++) {
				long long target = (1LL << i);
				int rem = target - ele;
				if (rem > ele) break;
				ans += mp[rem];
				ans %= mod;
			}
			mp[ele]++;
		}
		return ans;
	}
};