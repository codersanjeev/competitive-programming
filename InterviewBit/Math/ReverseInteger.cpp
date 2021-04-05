int Solution::reverse(int A) {
	bool isNegative = false;
	if (A < 0) {
		A *= -1;
		isNegative = true;
	}
	int ans = 0;
	int divisor = 1;
	while (A / divisor >= 10) {
		divisor *= 10;
	}
	int i = 0;
	while (A > 0) {
		int left = A / divisor;
		ans += (left * pow(10, i));
		i++;
		A %= divisor;
		divisor /= 10;
	}
	// check overflow
	if (ans == INT_MIN) {
		return 0;
	}
	if (isNegative) {
		return ans * -1;
	} else {
		return ans;
	}
}