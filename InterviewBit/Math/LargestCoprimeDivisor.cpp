int Solution::cpFact(int A, int B) {
	if (__gcd(A, B) == 1) {
		return A;
	}
	return cpFact(A / __gcd(A, B), B);
}