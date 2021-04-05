int Solution::isPower(int A) {
	if (A < 2) {
		return 1;
	}
	for (int i = 2; i * i <= A; i++) {
		double x = log(A) / log(i);
		if (x - (int)x < 0.00000001) {
			return true;
		}
	}
	return false;
}