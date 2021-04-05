void calc(unordered_map<int, vector<pair<int, int>>>& m, vector<int>& ret) {
    for (auto& [x, nums] : m) {
        for (int i = 1; i < nums.size(); i++) {
            int manh = nums[i].first - nums[i - 1].first;
            int idx1 = nums[i].second, idx2 = nums[i - 1].second;
            if (ret[idx1] > manh) ret[idx1] = manh;
            if (ret[idx2] > manh) ret[idx2] = manh;
        }
    }
}
vector<int> solve(vector<vector<int>>& nums) {
    int n = nums.size();
    vector<int> ret(n, 1e9);
    unordered_map<int, vector<pair<int, int>>> x, y;
    for (int i = 0; i < nums.size(); i++) {
        x[nums[i][0]].push_back({nums[i][1], i});
        y[nums[i][1]].push_back({nums[i][0], i});
    }
    for (auto& [num, arr] : x) sort(arr.begin(), arr.end());
    for (auto& [num, arr] : y) sort(arr.begin(), arr.end());
    calc(x, ret);
    calc(y, ret);
    return ret;
}