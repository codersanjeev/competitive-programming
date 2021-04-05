int Solution::canJump(vector<int> &arr) {
	int n = arr.size() - 1;
	int i = n;
	while (i >= 0) {
		if ((i + arr[i]) >= n) {
			n = i;
		}
		i--;
	}
	return n == 0;
}
