class Solution {
   public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> mp;
        for (int wordIndex = 0; wordIndex < words.size(); ++wordIndex) mp[words[wordIndex]] = wordIndex;
        for (int wordIndex = 0; wordIndex < words.size(); ++wordIndex) {
            for (int len = 0; len <= words[wordIndex].size(); ++len) {
                string prefix = words[wordIndex].substr(0, len);
                string suffix = words[wordIndex].substr(len);
                if (equal(cbegin(prefix), cend(prefix), crbegin(prefix))) {
                    string suffixReversed = suffix;
                    reverse(begin(suffixReversed), end(suffixReversed));
                    if (mp.count(suffixReversed) > 0 && mp[suffixReversed] != wordIndex) {
                        ans.push_back({mp[suffixReversed], wordIndex});
                    }
                }
                if (equal(cbegin(suffix), cend(suffix), crbegin(suffix))) {
                    string prefixReversed = prefix;
                    reverse(begin(prefixReversed), end(prefixReversed));
                    if (mp.count(prefixReversed) > 0 && mp[prefixReversed] != wordIndex && suffix.size() > 0) {
                        ans.push_back({wordIndex, mp[prefixReversed]});
                    }
                }
            }
        }
        return ans;
    }
};