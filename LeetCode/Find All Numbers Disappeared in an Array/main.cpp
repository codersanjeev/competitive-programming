auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
        	int idx = abs(nums[i]);
        	idx--;
        	if (nums[idx] > 0) nums[idx] *= -1;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
        	if (nums[i] > 0) ans.push_back(i + 1);
        }
        return ans;
    }
};