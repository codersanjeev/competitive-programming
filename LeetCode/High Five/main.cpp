class Solution {
   public:
    vector<vector<int>> highFive(vector<vector<int>> &items) {
        unordered_map<int, vector<int>> mp;
        for (const auto &ele : items) {
            mp[ele[0]].push_back(ele[1]);
        }
        vector<vector<int>> ans;
        for (const auto &ele : mp) {
            int id = ele.first;
            vector<int> marks = ele.second;
            sort(marks.begin(), marks.end(), greater<int>());
            int curr = 0;
            for (int i = 0; i < 5; i++) {
                curr += marks[i];
            }
            curr /= 5;
            ans.push_back({id, curr});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};