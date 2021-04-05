class Solution {
  public:
	vector<int> topKFrequent(vector<int> &nums, int k) {
		map<int, int> mp;
		for (const auto &ele : nums) {
			mp[ele]++;
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		int i = 0;
		auto it = mp.begin();
		while (it != mp.end()) {
			pq.push({it->second, it->first});
			if (pq.size() > k) {
				pq.pop();
			}
			it++;
		}
		vector<int> ans;
		while (!pq.empty()) {
			auto ele = pq.top();
			pq.pop();
			ans.push_back(ele.second);
		}
		return ans;
	}
};