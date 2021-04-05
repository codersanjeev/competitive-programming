class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int x = 0, y = 0;
        for (const auto &ele : position) {
            if (ele % 2 == 0) {
                x++;
            } else {
                y++;
            }
        }
        return min(x, y);
    }
};