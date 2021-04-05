class Solution {
  public:
	string makeLargestSpecial(string S) {
		vector<string> ans;
		int count = 0;
		for (const auto &ch : S) {
			if (count == 0) {
				ans.push_back("");
			}
			ch == '1' ? count++ : count--;
			ans.back() += ch;
		}
		for (auto &x : ans) {
			x = '1' + makeLargestSpecial(x.substr(1, x.size() - 2)) + '0';
		}
		sort(ans.begin(), ans.end());
		reverse(ans.begin(), ans.end());
		string finalAns = "";
		for (const auto &ele : ans) {
			finalAns += ele;
		}
		return finalAns;
	}
};