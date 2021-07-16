class Solution {
   public:
    vector<vector<int>> fourSum(vector<int> &nums, int key) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int target = key - nums[i] - nums[j];
                int lo = j + 1, hi = n - 1;
                while (lo < hi) {
                    int curr = nums[lo] + nums[hi];
                    if (curr == target) {
                        vector<int> temp = {nums[i], nums[j], nums[lo], nums[hi]};
                        ans.push_back(temp);
                        ++lo;
                        --hi;
                    } else if (curr > target) {
                        --hi;
                    } else {
                        ++lo;
                    }
                }
            }
        }
        auto makeUnique = [&](const vector<vector<int>> &arr) {
            set<vector<int>> ans(cbegin(arr), cend(arr));
            return vector<vector<int>>(cbegin(ans), cend(ans));
        };
        return makeUnique(ans);
    }
};