// find floor(x / y) using bitwise operators
int Solution::divide(int A, int B) {
	long long x = (long long)A;
	long long y = (long long)B;
	if (A == INT_MIN && B == -1) {
		return INT_MAX;
	}
	// make both x and y positive and remember the sign of result
	long long sign = ((x < 0) ^ (y < 0)) ? -1LL : 1LL;
	if (x == 0) {
		return 0;
	}
	x = abs(x);
	y = abs(y);
	if (y == 1) {
		return x * sign;
	}
	long long ans = 0LL;
	long long temp = 0LL;
	// start from the most significant bit
	for (long long i = 31LL; i >= 0LL; i--) {
		if (temp + (y << i) <= x) {
			temp += (y << i);
			ans |= (1LL << i);
		}
	}
	return (ans * sign);
}
