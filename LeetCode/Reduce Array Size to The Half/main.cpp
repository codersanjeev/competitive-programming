class Solution {
   public:
    int minSetSize(vector<int> &arr) {
        unordered_map<int, int> mp;
        for (const auto &ele : arr) {
            mp[ele]++;
        }
        int ans = 0;
        vector<pair<int, int>> freq;
        for (const auto &ele : mp) {
            freq.push_back(make_pair(ele.second, ele.first));
        }
        sort(freq.begin(), freq.end(), greater<pair<int, int>>());
        int curr = arr.size(), index = 0;
        while (curr > arr.size() / 2) {
            curr -= freq[index].first;
            ans++;
            index++;
        }
        return ans;
    }
};