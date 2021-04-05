
int Solution::solve(vector<int> &A, int B) {
	int n = A.size();
	sort(A.begin(), A.end());
	int ans = 0, lo = 0, hi = A[n - 1];
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int fi = A[0], temp = 1;
		for (int i = 1; i < n; i++) {
			if (A[i] - fi >= mid) {
				temp++;
				fi = A[i];
			}
		}
		if (temp < B) {
			hi = mid - 1;
		}
		else {
			ans = mid;
			lo = mid + 1;
		}
	}
	return ans;
}
