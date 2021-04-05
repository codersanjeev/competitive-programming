auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) {
            return arr;
        }
        int n = arr.size();
        vector<int> ans(n, 1), A = arr;
        map<int, int> mp;
        sort(A.begin(), A.end());
        mp[A[0]] = 1;
        for (int i = 1; i < n; i++) {
        	if (A[i] == A[i - 1]) {
        		ans[i] = ans[i - 1];
                mp[A[i]] = ans[i];
        	} else {
        		ans[i] = ans[i - 1] + 1;
                mp[A[i]] = ans[i];
        	}
        }
        for (int i = 0; i < n; i++) {
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};