class Solution {
   private:
    vector<string> grayCodeRecursive(int n) {
        if (n == 1) {
            return {"0", "1"};
        }
        vector<string> previousCodes = grayCodeRecursive(n - 1);
        vector<string> ans;
        for (const auto &ele : previousCodes) ans.push_back("0" + ele);
        reverse(previousCodes.begin(), previousCodes.end());
        for (const auto &ele : previousCodes) ans.push_back("1" + ele);
        return ans;
    }

    int toDecimal(const string &s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                ans |= (1 << i);
            }
        }
        return ans;
    }

   public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        vector<string> grayCodes = grayCodeRecursive(n);
        for (const auto &ele : grayCodes) {
            ans.push_back(toDecimal(ele));
        }
        return ans;
    }
};