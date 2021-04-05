class Solution {
  public:
	string defangIPaddr(string address) {
		string ans = "";
		for (const auto &ele : address) {
			if (ele == '.') {
				ans += "[.]";
			} else {
				ans += ele;
			}
		}
		return ans;
	}
};