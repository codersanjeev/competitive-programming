auto speedup = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

class Solution {
  public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		sort(coordinates.begin(), coordinates.end());
		int n = coordinates.size();
		set<double> st;
		for (int i = 1; i < n; i++) {
			double curr = (coordinates[i][1] - coordinates[i - 1][1]) * 1.0 / (coordinates[i][0] - coordinates[i - 1][0]);
			st.insert(curr);
		}
		return st.size() == 1;
	}
};