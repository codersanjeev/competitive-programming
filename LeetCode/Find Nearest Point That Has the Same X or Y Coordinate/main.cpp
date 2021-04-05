class Solution {
   public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1, mn = 1e9;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                int curr = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (curr < mn) {
                    mn = curr;
                    ans = i;
                }
            }
        }
        return ans;
    }
};