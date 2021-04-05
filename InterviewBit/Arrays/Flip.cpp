vector<int> Solution::flip(string A) {
	int n = A.size();
	vector<int> arr(n);
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (A[i] == '1') {
			arr[i] = -1;
		} else {
			flag = false;
			arr[i] = 1;
		}
	}
	if (flag) {
		return vector<int>(0);
	}
	int curr = 0, global = 0, j = 0, start = 0, end = 0;
	for (int i = 0; i < n; i++) {
		curr += arr[i];
		if (curr > global) {
			global = curr;
			start = j;
			end = i;
		}
		if (curr < 0) {
			curr = 0;
			j = i + 1;
		}
	}
	vector<int> ans = {start + 1, end + 1};
	return ans;
}