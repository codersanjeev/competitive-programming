class Solution {
   public:
    bool canBeIncreasing(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int prev = -1;
            bool found = true;
            for (int j = 0; j < nums.size(); ++j) {
                if (i != j) {
                    if (nums[j] > prev)
                        prev = nums[j];
                    else
                        found = false;
                }
            }
            if (found) return true;
        }
        return false;
    }
};