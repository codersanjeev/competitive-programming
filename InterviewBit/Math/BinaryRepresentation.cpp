string Solution::findDigitsInBinary(int A) {
	string ans;
	if (A == 0 || A == 1) {
		return to_string(A);
	}
	while (A != 0) {
		ans = ans + to_string(A & 1);
		A = A >> 1;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}