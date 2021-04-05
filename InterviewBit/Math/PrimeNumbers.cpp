vector<int> Solution::sieve(int A) {
	vector<bool> prime(A + 1, true);
	vector<int> ans;
	prime[1] = false;
	for (int i = 2; i * i <= A; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= A; j += i) {
				prime[j] = false;
			}
		}
	}
	for (int i = 2; i <= A; i++) {
		if (prime[i]) {
			ans.push_back(i);
		}
	}
	return ans;
}