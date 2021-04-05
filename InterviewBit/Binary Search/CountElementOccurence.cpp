int lowerBound(const vector<int> &A, int B) {
	int L = 0, H = A.size() - 1, ans = -1;
	while (L <= H) {
		int mid = L + (H - L) / 2;
		if (A[mid] == B) {
			ans = mid;
			H = mid - 1;
		} else if (A[mid] > B) {
			H = mid - 1;
		} else {
			L = mid + 1;
		}
	}
	return ans;
}

int upperBound(const vector<int> &A, int B) {
	int L = 0, H = A.size() - 1, ans = -1;
	while (L <= H) {
		int mid = L + (H - L) / 2;
		if (A[mid] == B) {
			ans = mid;
			L = mid + 1;
		} else if (A[mid] > B) {
			H = mid - 1;
		} else {
			L = mid + 1;
		}
	}
	return ans;
}

int Solution::findCount(const vector<int> &A, int B) {
	int L = lowerBound(A, B);
	int U = upperBound(A, B);
	if (L != -1 && U != -1) {
		return U - L + 1;
	} else {
		return 0;
	}
}