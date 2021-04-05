class Solution {
  public:
	int countTriplets(vector<int>& arr) {
		arr.insert(arr.begin(), 0);
		int n = arr.size(), ans = 0;
		for (int i = 1; i < n; i++) {
			arr[i] ^= arr[i - 1];
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[i] == arr[j]) {
					ans += (j - i - 1);
				}
			}
		}
		return ans;
	}
};