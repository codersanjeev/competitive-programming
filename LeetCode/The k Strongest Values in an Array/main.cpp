class Solution {
  public:
	vector<int> getStrongest(vector<int> &arr, int k) {
		int n = arr.size(), i = 0, j = n - 1;
		sort(arr.begin(), arr.end());
		int median = arr[(n - 1) / 2];
		vector<int> ans;
		while (ans.size() < k) {
			int x = abs(arr[i] - median);
			int y = abs(arr[j] - median);
			if (x > y) {
				ans.push_back(arr[i]);
				i++;
			} else {
				ans.push_back(arr[j]);
				j--;
			}
		}
		return ans;
	}
};