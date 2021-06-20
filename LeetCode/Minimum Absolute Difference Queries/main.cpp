class Solution {
   public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> prefix(nums.size(), vector<int>(101, 0));
        vector<int> freq(101, 0);
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
            for (int j = 0; j < 101; ++j) {
                prefix[i][j] = freq[j];
            }
        }
        vector<int> ans;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            vector<int> arr;
            for (int j = 0; j < 101; ++j) {
                if (prefix[r][j] > (l - 1 >= 0 ? prefix[l - 1][j] : 0)) {
                    arr.push_back(j);
                }
            }
            int curr = INT_MAX;
            for (int i = 1; i < arr.size(); ++i) {
                curr = min(curr, arr[i] - arr[i - 1]);
            }
            ans.push_back(curr == INT_MAX ? -1 : curr);
        }
        return ans;
    }
};