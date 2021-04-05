auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, mn = INT_MAX;
        for (const auto &ele : prices) {
            mn = min(mn, ele);
            ans = max(ans, ele - mn);
        }
        return ans;
    }
};