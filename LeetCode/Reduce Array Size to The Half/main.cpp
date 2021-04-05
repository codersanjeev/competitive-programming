class Solution {
  public:
	int minSetSize(vector<int>& arr) {
		map<int, int> mp;
		int n = arr.size();
		for (const auto &ele : arr) {
			mp[ele]++;
		}
		int ans = 0;
		vector<pair<int, int>> freq;
		for (const auto &ele : mp) {
			freq.push_back({ele.second, ele.first});
		}
		sort(freq.begin(), freq.end());
		reverse(freq.begin(), freq.end());
		int curr = n, idx = 0;
		while (curr > n / 2) {
			curr -= freq[idx].first;
			ans++;
			idx++;
		}
		return ans;
	}
};