bool isVowel(char ch) {
	return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int Solution::solve(string s) {
	int n = s.size();
	const int mod = 10003;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (isVowel(s[i])) {
			ans = (ans % mod + (n - i) % mod) % mod;
		}
	}
	return ans;
}
