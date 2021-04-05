class Solution {
   public:
    int maxAscendingSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> nums(n);
        nums[0] = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                nums[i] = nums[i - 1] + arr[i];
            } else {
                nums[i] = arr[i];
            }
        }
        return *max_element(nums.begin(), nums.end());
    }
};