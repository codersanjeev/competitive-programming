class Solution {
   public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // 0 1 2 ... n - 1 n n + 1 ... 2n - 1
        // 0 n 1 n + 1 2 n + 2 ... n - 1 2n - 1
        vector<int> ans(2 * n);
        int i = 0, j = n;
        for (int k = 0; k < 2 * n; k++) {
            ans[k] = (k % 2 == 0 ? nums[i] : nums[j]);
            if (k % 2 == 0)
                i++;
            else
                j++;
        }
        return ans;
    }
};