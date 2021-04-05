class Solution {
public:
    int countLargestGroup(int n) {
    	map<int, int> mp;
		for (int i = 1; i <= n; i++) {
			int sm = findSum(i);
			mp[sm]++;
		}
		int mx = INT_MIN;
		for (const auto &ele : mp) {
			mx = max(mx, ele.second);
		}
		int ans = 0;
		for (const auto &ele : mp) {
			if (ele.second == mx) {
				ans++;
			}
		}
		return ans;
    }
private:
	int findSum(int n) {
		int ans = 0;
		while (n > 0) {
			ans += n % 10;
			n /= 10;
		}
		return ans;
	}
};