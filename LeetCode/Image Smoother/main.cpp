auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int n = M.size(), m = M[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
        vector<int> dy = {1, -1, 0, -1, 1, 0, -1, 1};
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < m; j++) {
        		int cnt = 1;
        		ans[i][j] = M[i][j];
        		for (int k = 0; k < 8; k++) {
        			int x = i + dx[k];
        			int y = j + dy[k];
        			if (x >= 0 && y >= 0 && x < n && y < m) {
        				ans[i][j] += M[x][y];
        				cnt++;
        			}
        		}
        		ans[i][j] /= cnt;
            }
        }
        return ans;
    }
};