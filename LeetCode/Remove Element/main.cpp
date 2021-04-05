auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int j = 0, cnt = 0;
    	for (int i = 0; i < nums.size(); i++) {
    		if (nums[i] != val) {
    			nums[j++] = nums[i];
    		} else {
    			cnt++;
    		}
    	}
    	return nums.size() - cnt;
    }
};