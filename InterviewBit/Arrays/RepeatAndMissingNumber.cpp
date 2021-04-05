vector<int> Solution::repeatedNumber(const vector<int> &arr) {
	long long n = arr.size();
	long long temp1 = 0;
	for (long long i = 0; i < n; i++) {
		temp1 += (long long)arr[i];
	}
	long long temp2 = ((n * (n + 1)) / 2);
	long long diff = temp1 - temp2;
	temp1 = 0;
	for (long long i = 0; i < n; i++) {
		temp1 += (long long)((long long) arr[i] * (long long) arr[i]);
	}
	temp2 = ((n * (n + 1) * ((2 * n) + 1)) / 6);
	long long diff2 = temp1 - temp2;
	long long sum = diff2 / diff;
	long long A = (sum + diff) / 2;
	long long B = (sum - diff) / 2;
	vector<int> ans = {(int)A, (int)B};
	return ans;
}