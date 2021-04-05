class Solution {
  public:
	int maxArea(vector<int> &height) {
		int i = 0, j = height.size() - 1, ans = (j - i) * min(height[i], height[j]);
		while (i < j) {
			ans = max(ans, (j - i) * min(height[i], height[j]));
			if (height[i] == height[j]) {
				i++;
				j--;
			} else if (height[i] > height[j]) {
				j--;
			} else {
				i++;
			}
		}
		return ans;
	}
};