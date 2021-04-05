int Solution::anytwo(string s) {
	int n = s.size();
	unordered_map<char, int> mp;
	for (int i = 0; i < n; i++) {
		mp[s[i]]++;
		if (mp[s[i]] >= 3) {
			return 1;
		}
	}
	string temp;
	for (int i = 0; i < n; i++) {
		if (mp[s[i]] >= 2) {
			temp += s[i];
		}
	}
	string tempReverse = temp;
	reverse(tempReverse.begin(), tempReverse.end());
	return temp != tempReverse;
}