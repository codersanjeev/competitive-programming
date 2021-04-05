vector<int> Solution::nextPermutation(vector<int> &A) {
	int n = A.size();
	int i = n - 2;
	for (i = n - 2; i >= 0; i--) {
		if (A[i + 1] > A[i]) {
			break;
		}
	}
	if (i == -1) {
		sort(A.begin(), A.end());
		return A;
	}
	int j = n - 1;
	for (j = n - 1; j > i; j--) {
		if (A[j] > A[i]) {
			break;
		}
	}
	swap(A[i], A[j]);
	i = i + 1;
	j = n - 1;
	while (i < j) {
		swap(A[i], A[j]);
		i++;
		j--;
	}
	return A;
}
