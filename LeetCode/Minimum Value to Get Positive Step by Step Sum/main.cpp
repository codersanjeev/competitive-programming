class Solution {
public:
    int minStartValue(vector<int>& nums) {
    	int lo = 1, hi = INT_MAX, ans = 1;
    	while (lo <= hi) {
    		int mid = lo + (hi - lo) / 2;
    		if (isPossibleAnswer(nums, mid)) {
    			ans = mid;
    			hi = mid - 1;
    		} else {
    			lo = mid + 1;
    		}
    	}
    	return ans;
    }
private:
	bool isPossibleAnswer(const vector<int> &arr, int ele) {
		for (const auto &x : arr) {
			if (ele + x < 1) {
				return false;
			}
			ele += x;
		}
		return true;
	}
};