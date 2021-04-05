class Solution {
  public:
	bool backspaceCompare(string S, string T) {
		string a = "", b = "";
		for (const auto &ele : S) {
			if (ele == '#' && a.size() > 0) {
				a.pop_back();
			} else if (ele != '#') {
				a.push_back(ele);
			}
		}
		for (const auto &ele : T) {
			if (ele == '#' && b.size() > 0) {
				b.pop_back();
			} else if (ele != '#') {
				b.push_back(ele);
			}
		}
		return a == b;
	}
};