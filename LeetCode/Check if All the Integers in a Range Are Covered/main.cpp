class Solution {
   public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right) {
        vector<bool> visited(51, false);
        for (const auto &range : ranges) {
            for (int i = range[0]; i <= range[1]; ++i) {
                visited[i] = true;
            }
        }
        for (int i = left; i <= right; ++i) {
            if (visited[i] == false) {
                return false;
            }
        }
        return true;
    }
};