vector<int> Solution::maxone(vector<int> &arr, int m) {
	long long n = arr.size();
	long long i = 0LL, j = 0LL, zeros = 0LL, mx = LLONG_MIN;
	long long s, e;
	while (j < n) {
		if (zeros <= m) {
			if (arr[j] == 0) {
				zeros++;
			}
			j++;
		}
		if (zeros > m) {
			if (arr[i] == 0) {
				zeros--;
			}
			i++;
		}
		if (j - i + 1 > mx) {
			mx = j - i + 1;
			s = i;
			e = j;
		}
	}
	vector<int> ans;
	for (int i = s; i < e; i++) {
		ans.push_back(i);
	}
	return ans;
}
