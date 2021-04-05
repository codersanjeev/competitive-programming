auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
        	if (nums[i] > 0) {
        		nums[i] = nums[i - 1] + 1;
        	}
        }
        return *max_element(nums.begin(), nums.end());
    }
};