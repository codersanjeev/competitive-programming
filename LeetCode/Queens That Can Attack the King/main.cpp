class Solution {
  public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		set<pair<int, int>> st;
		for (const auto &ele : queens) {
			st.insert({ele[0], ele[1]});
		}
		vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
		vector<int> dy = {1, -1, 1, 0, -1, 1, 0, -1};
		vector<vector<int>> ans;
		for (int i = 0; i < 8; i++) {
			int x = king[0], y = king[1];
			while (x >= 0 && y >= 0 && x < 8 && y < 8 && st.count({x, y}) == 0) {
				x += dx[i];
				y += dy[i];
			}
			if (st.count({x, y}) > 0) {
				ans.push_back({x, y});
			}
		}
		return ans;
	}
};