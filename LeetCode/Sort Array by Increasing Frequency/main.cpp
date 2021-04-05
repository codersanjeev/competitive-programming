class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
    	map<int, int> mp;
    	for (const auto &ele : nums) {
    		mp[ele]++;
    	}
    	vector<pair<int, int>> arr(mp.begin(), mp.end());
    	sort(arr.begin(), arr.end(), [&](const pair<int, int> &x, const pair<int, int> &y) {
    		if (x.second == y.second) {
    			return x.first > y.first;
    		} else {
    			return x.second < y.second;
    		}
    	});
    	vector<int> ans;
    	for (const auto &ele : arr) {
    		int cnt = ele.second;
    		while (cnt--) {
    			ans.push_back(ele.first);
    		}
    	}
    	return ans;
    }
};