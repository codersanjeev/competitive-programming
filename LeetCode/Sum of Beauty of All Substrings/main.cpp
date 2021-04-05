auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> freq(26, 0);
                for (int k = i; k <= j; k++) {
                    freq[s[k] - 'a']++;
                }
                int mx = *max_element(freq.begin(), freq.end());
                int mn = 1e9;
                for (const auto &ele : freq) {
                    if (ele > 0) {
                        mn = min(mn, ele);
                    }
                }
                ans += (mx - mn);
            }
        }
        return ans;
    }
};