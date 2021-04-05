class Solution {
  public:
	vector<string> removeSubfolders(vector<string>& folder) {
		sort(folder.begin(), folder.end(), [](const string & a, const string & b) {
			return a < b;
		});
		vector<string> ans;
		ans.push_back(folder[0]);
		for (int i = 1; i < folder.size(); i++) {
			if (folder[i].find(ans.back() + "/") == string::npos) {
				ans.push_back(folder[i]);
			}
		}
		return ans;
	}
};