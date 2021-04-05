class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    	int ans = 0;
    	map<int, int> mp;
    	for (const auto &ele : dominoes) {
    		int curr = min(ele[0], ele[1]) * 10 + max(ele[0], ele[1]);
    		mp[curr]++;
    	}
    	for (const auto &ele : mp) {
    		int cnt = ele.second;
    		ans += (cnt * (cnt - 1)) / 2;
    	}
    	return ans;
    }
};