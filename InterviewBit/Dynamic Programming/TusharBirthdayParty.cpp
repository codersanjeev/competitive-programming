int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
	int capacity = *max_element(A.begin(), A.end());
	vector<long> arr(capacity + 1, INT_MAX);
	arr[0] = 0 ;
	for (int i = 0 ; i < B.size() ; i ++ )
		for (int j = B[i] ; j <= capacity ; j ++ ) {
			arr[j] = min(arr[j - B[i]] + C[i], arr[j]);
		}
	for (auto cap : A) { arr[0] += arr[cap]; }
	return arr[0];
}
