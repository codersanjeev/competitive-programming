class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        sort(sortedHeights.begin(), sortedHeights.end());
        int ans = 0, n = heights.size();
        for (int i = 0; i < n; i++) {
            if (heights[i] != sortedHeights[i]) {
                ans++;
            }
        }
        return ans;
    }
};