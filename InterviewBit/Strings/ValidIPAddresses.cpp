bool isValid(string s) {
	int ans = 0;
	for (auto ch : s) {
		ans = (ans * 10) + (ch - '0');
	}
	if (s[0] == '0' && s.size() != 1) {
		return false;
	}
	return ans >= 0 && ans < 256;
}

vector<string> Solution::restoreIpAddresses(string s) {
	int n = s.size();
	vector<string> ans;
	if (n < 4 || n > 12) {
		return ans;
	}
	if (n == 12) {
		string ip = "";
		for (int i = 0; i < 12; i++) {
			if (i % 3 == 0 && i != 0) {
				ip += ".";
			}
			ip += s[i];
		}
		ans.push_back(ip);
	}
	for (int i = 1; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				string a = s.substr(0, i);
				string b = s.substr(i, j - i);
				string c = s.substr(j, k - j);
				string d = s.substr(k, n - k);
				if (isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
					ans.push_back(a + "." + b + "." + c + "." + d);
				}
			}
		}
	}
	return ans;
}
