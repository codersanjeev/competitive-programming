class Solution {
  public:
	int leastInterval(vector<char> &tasks, int n) {
		map<int, int> mp;
		for (const auto &ele : tasks) {
			mp[ele]++;
		}
		int m = INT_MIN;
		for (const auto &ele : mp) {
			m = max(m, ele.second);
		}
		int cnt = 0;
		for (const auto &ele : mp) {
			if (ele.second == m) {
				cnt++;
			}
		}
		return max((int)tasks.size(), (m - 1) * (n + 1) + cnt);
	}
};