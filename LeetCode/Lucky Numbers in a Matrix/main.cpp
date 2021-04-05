class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int x = INT_MIN, y = INT_MAX;
        for (int i = 0; i < n; i++) {
            int mn = INT_MAX;
            for (int j = 0; j < m; j++) {
                mn = min(mn, matrix[i][j]);
            }
            x = max(x, mn);
        }
        for (int j = 0; j < m; j++) {
            int mx = INT_MIN;
            for (int i = 0; i < n; i++) {
                mx = max(mx, matrix[i][j]);
            }
            y = min(y, mx);
        }
        return (x == y ? vector<int>{x} : vector<int>{});
    }
};