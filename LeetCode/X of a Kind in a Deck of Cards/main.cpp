class Solution {
  public:
	bool hasGroupsSizeX(vector<int>& deck) {
		map<int, int> mp;
		for (const auto &ele : deck) {
			mp[ele]++;
		}
		int ans = 0;
		for (const auto &ele : mp) {
			ans = gcd(ans, ele.second);
		}
		return ans >= 2;
	}
};