class Solution {
  public:
	int largestAltitude(vector<int> &gain) {
		vector<int> ans;
		ans.push_back(0);
		for (const auto &ele : gain) {
			ans.push_back(ans.back() + ele);
		}
		return *max_element(ans.begin(), ans.end());
	}
};