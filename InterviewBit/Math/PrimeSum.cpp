vector<int> Solution::primesum(int A) {
	vector<bool> isPrime(A + 1, true);
	isPrime[1] = true;
	for (int i = 2; i * i <= A; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= A; j += i) {
				isPrime[j] = false;
			}
		}
	}
	vector<int> primes;
	for (int i = 2; i <= A; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
		}
	}
	int i = 0, j = primes.size() - 1;
	vector<int> ans(2);
	if (A == 4) {
		ans[0] = 2;
		ans[1] = 2;
		return ans;
	}
	while (i < j) {
		int curr = primes[i] + primes[j];
		if (curr == A) {
			ans[0] = primes[i];
			ans[1] = primes[j];
			break;
		} else if (curr < A) {
			i++;
		} else {
			j--;
		}
	}
	return ans;
}