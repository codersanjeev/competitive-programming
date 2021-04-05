class Solution {
  public:
	string reverseWords(string s) {
		string ans = "";
		stack<char> st;
		for (const auto &ch : s) {
			if (ch == ' ') {
				while (!st.empty()) {
					ans += st.top();
					st.pop();
				}
				ans += " ";
			} else {
				st.push(ch);
			}
		}
		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}
		return ans;
	}
};