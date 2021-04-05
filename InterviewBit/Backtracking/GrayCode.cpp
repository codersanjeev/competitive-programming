void grayCodeUtil(vector<int> &arr, int n, int &num) {
	if (n == 0) {
		arr.push_back(num);
		return;
	}
	grayCodeUtil(arr, n - 1, num);
	num ^= (1 << (n - 1));
	grayCodeUtil(arr, n - 1, num);
}

vector<int> Solution::grayCode(int n) {
	vector<int> ans;
	int num = 0;
	grayCodeUtil(ans, n, num);
	return ans;
}
