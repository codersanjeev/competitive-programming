int Solution::gcd(int A, int B) {
	int x = max(A, B);
	int y = min(A, B);
	if (y == 0) {
		return x;
	}
	return gcd(x % y, y);
}