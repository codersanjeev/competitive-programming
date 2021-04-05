class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < m; j++) {
        		if (mat[i][j] == 1) {
        			bool good = true;
        			for (int k = 0; k < n; k++) {
        				if (k != i && mat[k][j] == 1) {
        					good = false;
        					break;
        				}
        			}
        			for (int k = 0; good && k < m; k++) {
        				if (k != j && mat[i][k] == 1) {
        					good = false;
        					break;
        				}
        			}
        			if (good) {
        				ans++;
        			}
        		}
        	}
        }
        return ans;
    }
};