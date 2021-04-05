class Solution {
  public:
	vector<int> decode(vector<int> &encoded, int first) {
		vector<int> ans;
		ans.push_back(first);
		for (const auto &ele : encoded) {
			ans.push_back(ans.back() ^ ele);
		}
		return ans;
	}
};