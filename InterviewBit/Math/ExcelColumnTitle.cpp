string Solution::convertToTitle(int A) {
	unordered_map<int, char> mp;
	int x = 0;
	char y = 'A';
	while (x < 26) {
		mp[x] = y;
		x++;
		y++;
	}
	string ans = "";
	while (A != 0) {
		int rem = (A - 1) % 26;
		ans += mp[rem];
		A = (A - 1) / 26;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}