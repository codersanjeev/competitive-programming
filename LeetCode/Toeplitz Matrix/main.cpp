class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool ans = true;
        for (int i = 0; i < m; i++) {
        	int x = i, y = 0;
        	set<int> st;
        	while (x >= 0 && y >= 0 && x < m && y < n) {
        		st.insert(matrix[x][y]);
        		x++;
        		y++;
        	}
        	ans = ans & (st.size() == 1);
        }
        for (int j = 0; j < n; j++) {
        	int x = 0, y = j;
        	set<int> st;
        	while (x >= 0 && y >= 0 && x < m && y < n) {
        		st.insert(matrix[x][y]);
        		x++;
        		y++;
        	}
        	ans = ans & (st.size() == 1);	
        }
        return ans;
    }
};