string Solution::countAndSay(int n) {
	// base case
	if (n == 1) {
		return "1";
	} else {
		// buid answer in ans variable
		string ans = "";
		// recursive call for n - 1
		string s = countAndSay(n - 1);
		int i = 0;
		int len = s.size();
		while (i < len) {
			int cnt = 1;
			// count continuous same characters
			char ch = s[i];
			i++;
			while (i < len && s[i] == ch) {
				cnt++;
				i++;
			}
			// cnt times ch
			// append to answer string
			ans += to_string(cnt);
			ans += ch;
		}
		return ans;
	}
}
