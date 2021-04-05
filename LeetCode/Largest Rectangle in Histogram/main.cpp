class Solution {
  public:
	int largestRectangleArea(vector<int> &arr) {
		int n = arr.size(), ans = 0;
		vector<int> left(n, -1), right(n, n);
		for (int i = 1; i < n; i++) {
			int p = i - 1;
			while (p >= 0 && arr[p] >= arr[i]) {
				p = left[p];
			}
			left[i] = p;
		}
		for (int i = n - 2; i >= 0; i--) {
			int p = i + 1;
			while (p < n && arr[p] >= arr[i]) {
				p = right[p];
			}
			right[i] = p;
		}
		for (int i = 0; i < n; i++) {
			ans = max(ans, arr[i] * (right[i] - left[i] - 1));
		}
		return ans;
	}
};