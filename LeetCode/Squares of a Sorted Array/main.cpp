class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1, k = n - 1;
        vector<int> ans(n);
        while (i <= j) {
            int x = nums[i];
            int y = nums[j];
            if ((x * x) < (y * y)) {
                ans[k--] = y * y;
                j--;
            } else {
                ans[k--] = x * x;
                i++;
            }
        }
        return ans;
    }
};