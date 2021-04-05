bool solve(string s) {
	int n = s.size();
	for (int i = n / 2; i >= 1; i--) {
		if (n % i == 0) {
			int rep = n / i;
			string curr = s.substr(0, i);
			string ans = "";
			while (rep--) {
				ans += curr;
			}
			if (ans == s) {
				return true;
			}
		}
	}
	return false;
}