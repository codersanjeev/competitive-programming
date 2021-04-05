int Solution::maxSpecialProduct(vector<int> &A) {
	long long n = A.size();
	const long long mod = 1000000007;
	vector<long long> left(n);
	vector<long long> right(n);
	left[0] = 0;
	right[n - 1] = 0;
	stack<long long> st;
	st.push(0);
	for (long long i = 1; i < n; i++) {
		while (!st.empty() && A[st.top()] <= A[i]) {
			st.pop();
		}
		if (st.empty()) {
			left[i] = 0;
		} else {
			left[i] = st.top();
		}
		st.push(i);
	}
	while (!st.empty()) {
		st.pop();
	}
	st.push(n - 1);
	for (long long i = n - 2; i >= 0; i--) {
		while (!st.empty() && A[st.top()] <= A[i]) {
			st.pop();
		}
		if (st.empty()) {
			right[i] = 0;
		} else {
			right[i] = st.top();
		}
		st.push(i);
	}
	long long ans = LLONG_MIN;
	for (long long i = 0; i < n; i++) {
		ans = max(ans, left[i] * right[i]);
	}
	return (int)(ans % mod);
}