
// (x ^ y) % d ?
int Solution::pow(int x, int y, int d) {
	long long ans = 1LL;
	long long base = (long long) x;
	if (x == 0) {
		return 0;
	}
	if (y == 0) {
		return 1;
	}
	while (y != 0) {
		if (y & 1) {
			ans = (ans * base) % d;
		}
		base = (base * base) % d;
		y = y >> 1;
		if (ans > d) {
			ans = ans % d;
		}
	}
	if (ans < 0) {
		return d - abs(ans) % d;
	}
	return (int) ans % d;
}
