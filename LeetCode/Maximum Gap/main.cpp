class Solution {
   public:
    int maximumGap(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        double bucket = double(mx - mn) / double(n - 1);
        vector<int> maxElement(n, INT_MIN);
        vector<int> minElement(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            int index = (bucket == 0 ? 0 : (nums[i] - mn) / bucket);
            maxElement[index] = max(maxElement[index], nums[i]);
            minElement[index] = min(minElement[index], nums[i]);
        }
        int ans = 0, previous = maxElement[0];
        for (int i = 1; i < n; ++i) {
            if (minElement[i] == INT_MAX) continue;
            ans = max(ans, minElement[i] - previous);
            previous = maxElement[i];
        }
        return ans;
    }
};