int Solution::isPalindrome(string A) {
	string s = "";
	int n = A.size();
	for (int i = 0; i < n; i++) {
		if (A[i] != ' ') {
			if (A[i] >= 'A' && A[i] <= 'Z') {
				s += tolower(A[i]);
			} else if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= '0' && A[i] <= '9')) {
				s += A[i];
			}
		}
	}
	int m = s.size();
	int lo = 0;
	int hi = m - 1;
	while (lo <= hi) {
		if (s[lo] != s[hi]) {
			return 0;
		}
		lo++;
		hi--;
	}
	return 1;
}
