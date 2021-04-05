void Solution::merge(vector<int> &A, vector<int> &B) {
	int m = A.size();
	int n = B.size();
	int i = m - 1, j = n - 1;
	A.resize(m + n);
	int k = m + n - 1;
	while (i >= 0 && j >= 0) {
		if (A[i] > B[j]) {
			A[k] = A[i];
			i--;
		} else {
			A[k] = B[j];
			j--;
		}
		k--;
	}
	while (j >= 0) {
		A[k] = B[j];
		j--;
		k--;
	}
}
