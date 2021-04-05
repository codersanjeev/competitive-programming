vector<int> solve(vector<int>& nums, int k) {
    int n = nums.size(), i = 0, j = 0;
    list<int> l;
    vector<int> ans;
    while (j < n) {
        while (!l.empty() && l.back() < nums[j]) {
            l.pop_back();
        }
        l.push_back(nums[j]);
        if (j - i + 1 < k) {
            j++;
        } else if (j - i + 1 == k) {
            ans.push_back(l.front());
            if (l.front() == nums[i]) {
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}