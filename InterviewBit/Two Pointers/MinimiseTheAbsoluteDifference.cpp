int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {

	int i = A.size() - 1;
	int j = B.size() - 1;
	int k = C.size() - 1;

	int ans = abs(max({A[i], B[j], C[k]}) - min({A[i], B[j], C[k]}));

	while(i != -1 && j != -1 && k != -1) {
		int curr = abs(max({A[i], B[j], C[k]}) - min({A[i], B[j], C[k]}));
		ans = min(ans, curr);
		int mx = max({A[i], B[j], C[k]});
		if(mx == A[i]) {
			i--;
		}
		else if(mx == B[j]) {
			j--;
		}
		else if(mx == C[k]) {
			k--;
		}
	}

	return ans;

}
