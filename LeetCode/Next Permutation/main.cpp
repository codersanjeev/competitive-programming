class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = n - 2;
        if (n == 1) {
            return;
        }
        while (index >= 0 && nums[index] >= nums[index + 1]) {
            index--;
        }
        if (index < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int indexTwo = n - 1;
        while (nums[index] >= nums[indexTwo]) {
            indexTwo--;
        }
        swap(nums[index], nums[indexTwo]);
        int lo = index + 1, hi = n - 1;
        while (lo < hi) {
            swap(nums[lo], nums[hi]);
            lo++;
            hi--;
        }
    }
};