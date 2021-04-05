vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
	vector<int> ans;
	int n = A.size();
	int m = B.size();
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (A[i] == B[j]) {
			ans.push_back(A[i]);
			i++;
			j++;
		} else if (A[i] < B[j]) {
			i++;
		} else {
			j++;
		}
	}
	return ans;
}
