class Solution {
public:
    int findLucky(vector<int>& arr) {
    	map<int, int> mp;
    	for (const auto &ele : arr) {
    		mp[ele]++;
    	}
    	int ans = -1;
    	for (const auto &ele : mp) {
    		if (ele.first == ele.second) {
    			ans = max(ans, ele.first);
    		}
    	}
    	return ans;
    }
};