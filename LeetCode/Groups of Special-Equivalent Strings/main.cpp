class Solution {
  public:
	int numSpecialEquivGroups(vector<string> &A) {
		set<pair<string, string>> ans;
		for (const auto &ele : A) {
			pair<string, string> curr;
			for (int i = 0; i < ele.size(); i++) {
				if (i % 2 == 0) {
					curr.first += ele[i];
				} else {
					curr.second += ele[i];
				}
			}
			sort(curr.first.begin(), curr.first.end());
			sort(curr.second.begin(), curr.second.end());
			ans.insert(curr);
		}
		return ans.size();
	}
};