int Solution::threeSumClosest(vector<int> &arr, int k) {
	sort(arr.begin(), arr.end());
	long long n = arr.size();
	long long diff = LLONG_MAX, ans;
	for (long long i = 0; i < n - 1; i++) {
		long long lo = i + 1, hi = n - 1;
		while (lo < hi) {
			long long temp = arr[lo] + arr[hi] + arr[i];
			if (abs(temp - k) < diff) {
				diff = abs(temp - k);
				ans = temp;
			}
			(temp < k) ? lo++ : hi--;
		}
	}
	return ans;
}
