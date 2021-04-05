auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        if (n == 0) return ans;
        ans.push_back({1});
        for (int i = 1; i < n; i++) {
        	vector<int> curr(i + 1, 1);
        	for (int j = 1; j < i; j++) {
        		curr[j] = ans[i - 1][j] + ans[i - 1][j - 1];
        	}
        	ans.push_back(curr);
        }
        return ans;
    }
};