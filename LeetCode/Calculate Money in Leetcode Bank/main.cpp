class Solution {
  public:
	int totalMoney(int n) {
		vector<int> arr(1001);
		arr[0] = 0;
		arr[1] = 1;
		for (int i = 2; i <= 1000; i++) {
			if ((i - 1) % 7 == 0) {
				arr[i] = 1 + arr[i - 7];
			} else {
				arr[i] = 1 + arr[i - 1];
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += arr[i];
		}
		return ans;
	}
};