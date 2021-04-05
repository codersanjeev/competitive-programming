class Solution {
  public:
	int longestConsecutive(vector<int> &nums) {
		unordered_set<int> st(nums.begin(), nums.end());
		int ans = 0;
		for (const auto &ele : st) {
			if (st.count(ele - 1) == 0) {
				int currentNumber = ele, currentAnswer = 1;
				while (st.count(currentNumber + 1) > 0) {
					currentAnswer++;
					currentNumber++;
				}
				ans = max(ans, currentAnswer);
			}
		}
		return ans;
	}
};