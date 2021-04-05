class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        used.resize(nums.size(), false);
        vector<int> temp;
        permuteUniqueUtil(nums, temp);
        return ans;
    }

   private:
    vector<vector<int>> ans;
    vector<bool> used;

    void permuteUniqueUtil(const vector<int> &nums, vector<int> &temp) {
        if (nums.size() == temp.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true || (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)) {
                continue;
            }
            used[i] = true;
            temp.push_back(nums[i]);
            permuteUniqueUtil(nums, temp);
            used[i] = false;
            temp.pop_back();
        }
    }
};