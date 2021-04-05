class Solution {
  public:
	int numOfSubarrays(vector<int>& arr, int k, int threshold) {
		int n = arr.size(), i = 0, j = k - 1, ans = 0;
		for (int i = 1; i < n; i++) {
			arr[i] += arr[i - 1];
		}
		while (j < n) {
			int curr = arr[j];
			if (i - 1 >= 0) {
				curr -= arr[i - 1];
			}
			if (curr / k >= threshold) {
				ans++;
			}
			i++;
			j++;
		}
		return ans;
	}
};