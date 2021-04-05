int Solution::isPalindrome(int A) {
	// this divisor will be used for getting
	// leftmost digit from the number
	// the right most digit can be extracted by taking mod with 10
	// base cases
	if (A < 0) {
		return 0;
	}
	if (A >= 0 && A <= 9) {
		return 1;
	}
	int divisor = 1;
	// number : divisor
	// 123    : 100
	// 12345  : 10000
	// 12     : 10
	while (A / divisor >= 10) {
		divisor *= 10;
	}
	while (A != 0) {
		int left = A / divisor;
		int right = A % 10;
		// not a palindrome
		if (left != right) {
			return 0;
		}
		// remove first and last digit from number
		A = (A % divisor) / 10;
		// decrement divisor
		divisor /= 100;
	}
	return 1;
}