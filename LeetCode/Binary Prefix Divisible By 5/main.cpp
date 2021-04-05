auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int num = 0, i = 0;
        vector<bool> ans(A.size(), false);
        for (const auto &ele : A) {
        	num <<= 1;
        	num += ele;
        	num %= 5;
        	if (num == 0) {
                ans[i] = true;
            }
            i++;
        }
        return ans;
    }
};