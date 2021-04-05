class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size(), i = 0, j = 1;
        vector<int> ans(n);
        for (const auto &ele : A) {
            if (ele % 2 == 0) {
                ans[i] = ele;
                i += 2;
            } else {
                ans[j] = ele;
                j += 2;
            }
        }
        return ans;
    }
};