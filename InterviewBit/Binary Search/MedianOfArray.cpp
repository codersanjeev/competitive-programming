double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
	int m = A.size(), n = B.size();
	if (m < n) { return findMedianSortedArrays(B, A); }
	int lo = 0, hi = n * 2;
	while (lo <= hi) {
		int mid2 = lo + (hi - lo) / 2;
		int mid1 = m + n - mid2;
		double L1 = (mid1 == 0) ? INT_MIN : A[(mid1 - 1) / 2];
		double L2 = (mid2 == 0) ? INT_MIN : B[(mid2 - 1) / 2];
		double R1 = (mid1 == m * 2) ? INT_MAX : A[mid1 / 2];
		double R2 = (mid2 == n * 2) ? INT_MAX : B[mid2 / 2];
		if (L1 > R2) {
			lo = mid2 + 1;
		} else if (L2 > R1) {
			hi = mid2 - 1;
		} else {
			return (max(L1, L2) + min(R1, R2)) / 2.0;
		}
	}
	return -1;
}
