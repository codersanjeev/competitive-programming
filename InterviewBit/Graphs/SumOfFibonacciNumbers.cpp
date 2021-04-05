int Solution::fibsum(int n) {
	int a = 1, b = 1;
	vector<int> fib;
	while (a <= n) {
		fib.push_back(a);
		int temp = a + b;
		a = b;
		b = temp;
	}
	int ans = 0;
	for (int i = fib.size() - 1; i >= 0; i--) {
		int curr = fib[i];
		while (curr <= n) {
			n -= curr;
			ans++;
		}
		if (n == 0) {
			break;
		}
	}
	return ans;
}
