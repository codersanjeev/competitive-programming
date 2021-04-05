class Solution {
   public:
    int secondHighest(string s) {
        vector<int> ans;
        for (const auto &ch : s) {
            if (isdigit(ch)) {
                ans.push_back(ch - '0');
            }
        }
        set<int> temp(ans.begin(), ans.end());
        while (ans.empty() == false) ans.pop_back();
        for (const auto &ele : temp) ans.push_back(ele);
        sort(ans.begin(), ans.end());
        return (ans.size() < 2 ? -1 : ans[ans.size() - 2]);
    }
};