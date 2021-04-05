int Solution::jump(vector<int> &A) {
	int n = A.size();
	if (n == 0) { return 0; }
	vector<int> minJumps(n, -1);
	minJumps[0] = 0;
	int i = 0, j = 1;
	while (i < n) {
		if (minJumps[i] == -1) { return -1; }
		while (j < n && j - i <= A[i]) {
			minJumps[j] = minJumps[i] + 1;
			j++;
		}
		i++;
	}
	return minJumps[n - 1];
}
