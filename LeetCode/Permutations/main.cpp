class Solution {
   public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> temp;
        permuteUtil(nums, temp);
        return ans;
    }

   private:
    vector<vector<int>> ans;
    unordered_map<int, int> visited;

    void permuteUtil(const vector<int> &nums, vector<int> &temp) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (const auto &ele : nums) {
            if (visited[ele] == 1) {
                continue;
            }
            temp.push_back(ele);
            visited[ele] = 1;
            permuteUtil(nums, temp);
            temp.pop_back();
            visited[ele] = 0;
        }
    }
};