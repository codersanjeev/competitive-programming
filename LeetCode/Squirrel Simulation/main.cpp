class Solution {
   public:
    int minDistance(int n, int m, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int total = 0, maxDistance = INT_MIN;
        for (const auto& ele : nuts) {
            total += (findDistance(ele, tree) * 2);
            maxDistance = max(maxDistance, findDistance(ele, tree) - findDistance(ele, squirrel));
        }
        return total - maxDistance;
    }

   private:
    int findDistance(const vector<int>& a, const vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};