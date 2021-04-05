class Solution {
   public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long double s = accumulate(nums.begin(), nums.end(), 0.0);
        long double x = s - (goal * 1.0);
        if (x < 0) x *= -1;
        x = x / (limit * 1.0);
        return ceil(x);
    }
};