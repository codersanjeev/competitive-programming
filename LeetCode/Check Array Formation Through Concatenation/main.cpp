class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> mp;
        for (const auto &piece : pieces) {
            mp[piece[0]] = piece;
        }
        int idx = 0, n = arr.size();
        while (idx < n) {
            if (!mp.count(arr[idx])) {
                return false;
            }
            for (const auto &ele : mp[arr[idx]]) {
                if (ele != arr[idx]) {
                    return false;
                }
                idx++;
            }
        }
        return idx == n;
    }
};