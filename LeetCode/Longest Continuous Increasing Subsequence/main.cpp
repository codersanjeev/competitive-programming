auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, i = 0, n = nums.size();
        for (int j = 0; j < n; j++) {
        	if (j > 0 && nums[j - 1] >= nums[j]) {
        		i = j;
        	}
        	ans = max(ans, j - i + 1);
        }
        return ans;
    }
};