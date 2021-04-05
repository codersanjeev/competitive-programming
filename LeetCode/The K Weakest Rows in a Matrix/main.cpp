class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        set<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
        	int curr = accumulate(mat[i].begin(), mat[i].end(), 0);
        	st.insert({curr, i});
        }
        vector<int> ans;
        auto it = st.begin();
        while (k--) {
        	ans.push_back(it->second);
        	it++;
        }
        return ans;
    }
};