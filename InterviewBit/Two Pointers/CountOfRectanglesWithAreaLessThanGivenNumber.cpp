const int mod = 1e9 + 7;

int Solution::solve(vector<int> &arr, int k) {

	int n = arr.size();
	int lo = 0, hi = n - 1, ans = 0;
	while (lo <= hi) {
		if (((long long)arr[lo] * (long long)arr[hi]) < k) {
			ans = (ans + 2 * (hi - lo) + 1) % mod;
			lo++;
		}
		else {
			hi--;
		}
	}
	return ans;

}
