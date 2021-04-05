class Solution {
  public:
	int countGoodRectangles(vector<vector<int>> &rectangles) {
		int maxLen = INT_MIN, ans = 0;
		for (const auto &ele : rectangles) {
			maxLen = max(maxLen, min(ele[0], ele[1]));
		}
		for (const auto &ele : rectangles) {
			int curr = min(ele[0], ele[1]);
			if (curr == maxLen) {
				ans++;
			}
		}
		return ans;
	}
};