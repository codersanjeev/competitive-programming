int Solution::perfectPeak(vector<int> &A) {
	int n = A.size();
	if (n <= 2) return 0;
	vector<int> p;
	for (int i = 1; i < n - 1; i++) {
		if (A[i] > A[i - 1] && A[i] < A[i + 1]) {
			p.push_back(i);
		}
	}
	if (p.size() == 0) return 0;
	int left[n + 1];
	int right[n + 1];
	left[0] = A[0];
	right[n - 1] = A[n - 1];
	for (int i = 1; i < n; i++) {
		left[i] = max(left[i - 1], A[i]);
	}
	for (int i = n - 2; i >= 0; i--) {
		right[i] = min(right[i + 1], A[i]);
	}
	for (int i = 0; i < p.size(); i++) {
		int idx = p[i];
		if (left[idx - 1] < A[idx] && right[idx + 1] > A[idx])
			return 1;
	}
	return 0;
}
