class Solution {
  public:
	string toLowerCase(string s) {
		string ans = "";
		for (const auto &ele : s) {
			ans += tolower(ele);
		}
		return ans;
	}
};