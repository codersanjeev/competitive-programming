auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> mp;
        for (const auto &ele : nums) {
        	mp[ele]++;
        }
        int mx = INT_MIN;
        for (const auto &ele : mp) {
        	mx = max(mx, ele.second);
        }
        vector<int> candidates;
        for (const auto &ele : mp) {
        	if (ele.second == mx) {
        		candidates.push_back(ele.first);
        	}
        }
        int ans = INT_MAX;
        for (const auto &ele : candidates) {
        	int start = 0, end = nums.size() - 1;
        	while (nums[start] != ele) start++;
        	while (nums[end] != ele) end--;
        	ans = min(ans, end - start + 1);
        }
        return ans;
    }
};