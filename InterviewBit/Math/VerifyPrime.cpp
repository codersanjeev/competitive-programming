int Solution::isPrime(int A) {
	if (A == 1) {
		return 0;
	}
	for (int i = 2; i * i <= A; i++) {
		if (A % i == 0) {
			return 0;
		}
	}
	return 1;
}