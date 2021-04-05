string solve(string a, string b) {
	int n = a.size(), m = b.size();
	string ans = "";
	int i = n - 1, j = m - 1, carry = 0;
	while (i >= 0 && j >= 0) {
		int x = a[i] - '0';
		int y = b[j] - '0';
		int curr = x + y + carry;
		ans += to_string(curr % 2);
		carry = curr / 2;
		i--;
		j--;
	}
	while (i >= 0) {
		int x = a[i] - '0';
		int curr = x + carry;
		ans += to_string(curr % 2);
		carry = curr / 2;
		i--;
	}
	while (j >= 0) {
		int y = b[j] - '0';
		int curr = y + carry;
		ans += to_string(curr % 2);
		carry = curr / 2;
		j--;
	}
	if (carry > 0) {
		ans += to_string(carry);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}