string Solution::addBinary(string A, string B) {
	int n = A.size();
	int m = B.size();
	if (n < m) {
		string temp(m - n, '0');
		A = temp + A;
	} else if (n > m) {
		string temp(n - m, '0');
		B = temp + B;
	}
	n = A.size();
	string ans = "";
	int carry = 0;
	for (int i = n - 1; i >= 0; i--) {
		int curr = (A[i] - '0') + (B[i] - '0') + carry;
		if (curr == 0) {
			ans += "0";
			carry = 0;
		} else if (curr == 1) {
			ans += "1";
			carry = 0;
		} else if (curr == 2) {
			ans += "0";
			carry = 1;
		} else {
			ans += "1";
			carry = 1;
		}
	}
	if (carry == 1) {
		ans += "1";
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
