int Solution::numDecodings(string s) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	long long  len = s.size();
	if (len == 0) {
		return 0;
	}
	if (s[0] == '0') {
		return 0;
	}
	if (len == 1) {
		return 1;
	}
	long long count[len + 1];
	const int mod = 1e9 + 7;
	count[0] = 1; // empty
	count[1] = 1;
	for (int i = 2; i <= len; i++) {
		count[i] = 0;
		if (s[i - 1] > '0') {
			count[i] = count[i - 1];
		}
		if ((s[i - 2] < '2' && s[i - 2] > '0' ) || (s[i - 2] == '2' && s[i - 1] < '7')) {
			count[i] = (count[i] + count[i - 2]) % mod;
		}
	}
	return count[len] % mod;
}