#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edges;
        auto min_bricks = wall.size();
        for (auto row : wall)
            for (auto i = 0, width = 0; i < row.size() - 1; ++i)
                min_bricks = min(min_bricks, wall.size() - (++edges[width += row[i]]));
        return min_bricks;
    }
};