class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        if (nums.empty()) return nums;
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n - 1; i += 2) {
            vector<int> curr(nums[i], nums[i + 1]);
            ans.insert(ans.end(), curr.begin(), curr.end());
        }
        return ans;
    }
};