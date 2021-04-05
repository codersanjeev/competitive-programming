unsigned int Solution::reverse(unsigned int n) {
	int po = 31;
	unsigned int ans = 0;
	while (n) {
		if (n & 1) {
			ans += pow(2, po);
		}
		n >>= 1;
		po--;
	}
	return ans;
}
