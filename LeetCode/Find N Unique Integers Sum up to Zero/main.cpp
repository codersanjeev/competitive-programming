class Solution {
public:
    vector<int> sumZero(int n) {
        if (n == 1) return {0};
        int curr = 0;
        vector<int> ans;
        for (int i = 1; i < n; i++) {
            ans.push_back(i);
            curr += i;
        }
        ans.push_back(curr * -1);
        return ans;
    }
};