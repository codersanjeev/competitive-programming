class Solution {
  public:
	int findKthLargest(vector<int> &nums, int k) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (const auto &ele : nums) {
			pq.push(ele);
			if (pq.size() > k) {
				pq.pop();
			}
		}
		return pq.top();
	}
};