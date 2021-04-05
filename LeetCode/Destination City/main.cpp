class Solution {
  public:
	string destCity(vector<vector<string>> &paths) {
		map<string, int> in, out;
		set<string> st;
		for (const auto &ele : paths) {
			in[ele[0]]++;
			out[ele[1]]++;
			st.insert(ele[0]);
			st.insert(ele[1]);
		}
		string ans = "";
		for (const auto &ele : st) {
			if (out[ele] > 0 && in[ele] == 0) {
				ans = ele;
				break;
			}
		}
		return ans;
	}
};