class Solution {
  public:
	int maxResult(vector<int> &nums, int k) {
		deque<int> q;
		for (int i = 0; i < nums.size(); i++) {
			nums[i] += (q.empty() ? 0 : nums[q.front()]);
			while (!q.empty() && nums[q.back()] < nums[i]) {
				q.pop_back();
			}
			q.push_back(i);
			while (!q.empty() && i - q.front() + 1 > k) {
				q.pop_front();
			}
		}
		return nums.back();
	}
};