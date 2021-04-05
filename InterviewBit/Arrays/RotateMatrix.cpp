
void Solution::rotate(vector<vector<int> > &A) {
	long long n = A.size();
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < i; j++) {
			swap(A[i][j], A[j][i]);
		}
	}
	for (auto &row : A) {
		reverse(row.begin(), row.end());
	}
}