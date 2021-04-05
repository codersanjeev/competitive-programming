class Solution {
   public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int cnt = 0;
        for (const auto& ele : nums) {
            if (ele == target) {
                cnt++;
            } else if (ele > target) {
                break;
            }
        }
        return cnt > nums.size() / 2;
    }
};