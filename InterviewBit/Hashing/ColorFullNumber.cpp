int Solution::colorful(int A) {
	string s = to_string(A);
	int n = s.size();
	unordered_map<int, bool> mp;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int curr = 1;
			for (int k = i; k <= j; k++) {
				curr *= (s[k] - '0');
			}
			if (mp[curr] == true) {
				return 0;
			}
			mp[curr] = true;
		}
	}
	return 1;
}
