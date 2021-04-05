class Solution {
  public:
	int minOperations(vector<int> &nums, int x) {
		unordered_map<int, int> mp;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			mp[sum] = i;
		}
		mp[0] = 0;
		if (x > sum) {
			return -1;
		}
		sum -= x;
		int longest = 0, val = 0;
		for (int i = 0; i < nums.size(); i++) {
			val += nums[i];
			if (mp.count(val - sum)) {
				if (val - sum == 0) {
					longest = max(longest, i - mp[val - sum] + 1);
				} else {
					longest = max(longest, i - mp[val - sum]);
				}
			}
		}
		return (longest == 0 ? (sum == 0 ? nums.size() : -1) : nums.size() - longest);
	}
};