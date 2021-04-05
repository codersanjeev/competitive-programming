auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if (nums.size() < 2) return nums.size();
    	int i = 0, j = 1;
    	while (j < nums.size()) {
    		if (nums[j] != nums[i]) {
    			i++;
    			nums[i] = nums[j];
    		}
    		j++;
    	}
    	return i + 1;
    }
};