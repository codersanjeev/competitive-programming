class Solution {
  public:
	int minimumDeviation(vector<int> &nums) {
		for (auto &ele : nums) {
			if (ele % 2 == 1) {
				ele *= 2;
			}
		}
		int mn = *min_element(nums.begin(), nums.end());
		priority_queue<int> pq(nums.begin(), nums.end());
		int ans = INT_MAX;
		while (!pq.empty()) {
			int ele = pq.top();
			pq.pop();
			ans = min(ans, ele - mn);
			if (ele % 2 == 1) {
				break;
			}
			mn = min(mn, ele / 2);
			pq.push(ele / 2);
		}
		return ans;
	}
};