class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int count = 1, ans = nums[0];
    	for (int i = 1; i < nums.size(); i++) {
    		int ele = nums[i];
    		if (ele == ans) {
    			count++;
    		} else {
    			count--;
    		}
    		if (count == 0) {
    			ans = ele;
    			count = 1;
    		}
    	}
    	return ans;
    }
};